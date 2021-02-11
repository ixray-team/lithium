//
//  CNativeFileSystem.cpp
//  vfspp
//
//  Created by Yevgeniy Logachev on 6/23/16.
//
//
#include <vector>
#include <filesystem>
#include <algorithm>
#include <execution>

#ifdef _WIN32
#include <io.h>
#define access _access
#define W_OK 2
#else
#include <unistd.h>
#endif

#include "CNativeFileSystem.h"
//#include <dirent.h>
#include <fstream>
#include "CNativeFile.h"
#include "CStringUtilsVFS.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <string>
#include <stdio.h>

#ifdef _WIN32
#include <direct.h>

#undef CreateFile
#undef CopyFile
#define mkdir(path, mode) _mkdir(path)
#define snprintf(buffer, count, format, ...) _snprintf(buffer, count, format, __VA_ARGS__)
#else
#define MAX_PATH 255
#endif

using namespace vfspp;

// *****************************************************************************
// Public Methods
// *****************************************************************************

CNativeFileSystem::CNativeFileSystem(const std::string& basePath)
	: m_BasePath(basePath)
	, m_IsInitialized(false)
{
	if (!CStringUtils::EndsWith(m_BasePath, "/"))
	{
		m_BasePath += "/";
	}
}

CNativeFileSystem::~CNativeFileSystem()
{

}

void CNativeFileSystem::Initialize()
{
	namespace stdfs = std::filesystem;

	if (m_IsInitialized)
		return;

	auto& it = stdfs::recursive_directory_iterator(BasePath());
	std::vector<stdfs::directory_entry> cache;
	std::copy(stdfs::begin(it), stdfs::end(it), std::back_inserter(cache));

	std::mutex set_mtx;

	std::for_each(std::execution::par, cache.begin(), cache.end(), [&](stdfs::directory_entry& item) {
		
		if (item._Is_symlink_or_junction() || (!item.is_directory() && !item.is_regular_file()))
			return;

		stdfs::path rel = stdfs::relative(item, stdfs::path(BasePath()));
		
		CFileInfo fileInfo(m_BasePath, rel.generic_string(), item.is_directory());
		
		stdfs::perms permissions = item.status().permissions();
		bool isReadOnly = (access(item.path().generic_string().c_str(), W_OK) == -1);
		IFilePtr pfile = std::make_shared<CNativeFile>(fileInfo, isReadOnly);

		std::lock_guard<std::mutex> set_lock(set_mtx);
		m_FileList.insert(pfile);
	});

}

void CNativeFileSystem::Shutdown()
{
	m_BasePath = "";
	m_FileList.clear();
	m_IsInitialized = false;
}


bool CNativeFileSystem::IsInitialized() const
{
	return m_IsInitialized;
}


const std::string& CNativeFileSystem::BasePath() const
{
	return m_BasePath;
}


const IFileSystem::TFileList& CNativeFileSystem::FileList() const
{
	return m_FileList;
}


bool CNativeFileSystem::IsReadOnly() const
{
	if (!IsInitialized())
	{
		return true;
	}

	struct stat fileStat;
	if (stat(BasePath().c_str(), &fileStat) < 0) {
		return false;
	}
	return (fileStat.st_mode & _S_IREAD &~_S_IWRITE);
}


IFilePtr CNativeFileSystem::OpenFile(const CFileInfo& filePath, int mode)
{
	CFileInfo fileInfo(BasePath(), filePath.AbsolutePath(), false);
	IFilePtr file = FindFile(fileInfo);
	bool isExists = (file != nullptr);
	if (!isExists)
	{
		mode |= IFile::Truncate;
		file.reset(new CNativeFile(fileInfo));
	}
	file->Open(mode);

	if (!isExists && file->IsOpened())
	{
		m_FileList.insert(file);
	}

	return file;
}


void CNativeFileSystem::CloseFile(IFilePtr file)
{
	if (file)
	{
		file->Close();
	}
}


bool CNativeFileSystem::CreateFile(const CFileInfo& filePath)
{
	bool result = false;
	if (!IsReadOnly() && !IsFileExists(filePath))
	{
		CFileInfo fileInfo(BasePath(), filePath.AbsolutePath(), false);
		IFilePtr file = OpenFile(filePath, IFile::Out | IFile::Truncate);
		if (file)
		{
			result = true;
			file->Close();
		}
	}
	else
	{
		result = true;
	}

	return result;
}


bool CNativeFileSystem::RemoveFile(const CFileInfo& filePath)
{
	bool result = true;

	IFilePtr file = FindFile(filePath);
	if (!IsReadOnly() && file)
	{
		CFileInfo fileInfo(BasePath(), file->FileInfo().AbsolutePath(), false);
		if (remove(fileInfo.AbsolutePath().c_str()))
		{
			m_FileList.erase(file);
		}
	}

	return result;
}

bool CNativeFileSystem::CopyFile(const CFileInfo& src, const CFileInfo& dest)
{
	bool result = false;
	if (!IsReadOnly())
	{
		IFilePtr fromFile = FindFile(src);
		IFilePtr toFile = OpenFile(dest, IFile::Out);

		if (fromFile && toFile)
		{
			uint64_t size = 1024; //kChunkSize;
			std::vector<uint8_t> buff((size_t)size);
			do
			{
				fromFile->Read(buff.data(), 1024);
				toFile->Write(buff.data(), size);
			} while (size == 1024);

			result = true;
		}
	}

	return result;
}


bool CNativeFileSystem::RenameFile(const CFileInfo& src, const CFileInfo& dest)
{
	if (!IsReadOnly())
	{
		return false;
	}

	bool result = false;

	IFilePtr fromFile = FindFile(src);
	IFilePtr toFile = FindFile(dest);
	if (fromFile && !toFile)
	{
		CFileInfo toInfo(BasePath(), dest.AbsolutePath(), false);

		if (rename(fromFile->FileInfo().AbsolutePath().c_str(), toInfo.AbsolutePath().c_str()))
		{
			m_FileList.erase(fromFile);
			toFile = OpenFile(dest, IFile::In);
			if (toFile)
			{
				result = true;
				toFile->Close();
			}
		}
	}

	return result;
}


bool CNativeFileSystem::IsFileExists(const CFileInfo& filePath) const
{
	return (FindFile(BasePath() + filePath.AbsolutePath()) != nullptr);
}


bool CNativeFileSystem::IsFile(const CFileInfo& filePath) const
{
	IFilePtr file = FindFile(filePath);
	if (file)
	{
		return !file->FileInfo().IsDir();
	}

	return false;
}


bool CNativeFileSystem::IsDir(const CFileInfo& dirPath) const
{
	IFilePtr file = FindFile(dirPath);
	if (file)
	{
		return file->FileInfo().IsDir();
	}

	return false;
}

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************

IFilePtr CNativeFileSystem::FindFile(const CFileInfo& fileInfo) const
{
	TFileList::const_iterator it = std::find_if(m_FileList.begin(), m_FileList.end(), [&](IFilePtr file)
	{
		return file->FileInfo() == fileInfo;
	});

	if (it != m_FileList.end())
	{
		return *it;
	}

	return nullptr;
}

/*
void CNativeFileSystem::BuildFilelist(SDir* dir,
	std::string basePath,
	TFileList& outFileList)
{
	if (!CStringUtils::EndsWith(basePath, "/"))
	{
		basePath += "/";
	}

	struct dirent *ent;
	while ((ent = readdir(dir)) != NULL)
	{
		std::string filename = ent->d_name;
		std::string filepath = basePath + filename;
		SDir *childDir = static_cast<SDir*>(opendir(filepath.c_str()));
		bool isDotOrDotDot = CStringUtils::EndsWith(filename, ".") && childDir;
		if (childDir && !isDotOrDotDot)
		{
			filename += "/";
		}

		CFileInfo fileInfo(basePath, filename, childDir != NULL);
		if (!FindFile(fileInfo))
		{
			IFilePtr file(new CNativeFile(fileInfo));
			outFileList.insert(file);
		}

		if (childDir)
		{
			if (!isDotOrDotDot)
			{
				BuildFilelist(childDir, (childDir ? filepath : basePath), outFileList);
			}
			closedir(childDir);
		}
	}
}
*/