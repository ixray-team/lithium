//
//  CVirtualFileSystem.cpp
//  vfspp
//
//  Created by Yevgeniy Logachev on 6/23/16.
//
//

#include "CVirtualFileSystem.h"
#include "CStringUtilsVFS.h"

using namespace vfspp;

// *****************************************************************************
// Constants
// *****************************************************************************

static CVirtualFileSystemPtr g_FS;

// *****************************************************************************
// Public Methods
// *****************************************************************************

struct SAliasComparator
{
	bool operator()(const CVirtualFileSystem::SSortedAlias& a1, const CVirtualFileSystem::SSortedAlias& a2) const
	{
		return a1.alias.length() > a2.alias.length();
	}
};

void vfspp::vfs_initialize()
{
	if (!g_FS)
	{
		g_FS.reset(new CVirtualFileSystem());
	}
}

void vfspp::vfs_shutdown()
{
	g_FS = nullptr;
}

CVirtualFileSystemPtr vfspp::vfs_get_global()
{
	return g_FS;
}

CVirtualFileSystem::CVirtualFileSystem()
{
}

CVirtualFileSystem::~CVirtualFileSystem()
{
	std::for_each(m_FileSystem.begin(), m_FileSystem.end(), [](const TFileSystemMap::value_type& fs)
	{
		fs.second->Shutdown();
	});
}

void CVirtualFileSystem::AddFileSystem(const std::string& alias, IFileSystemPtr filesystem)
{
	if (!filesystem)
	{
		return;
	}

	std::string a = alias;
	if (!CStringUtils::EndsWith(a, "/"))
	{
		a += "/";
	}

	TFileSystemMap::const_iterator it = m_FileSystem.find(a);
	if (it == m_FileSystem.end())
	{
		m_FileSystem[a] = filesystem;
		m_SortedAlias.push_back(SSortedAlias(a, filesystem));
		m_SortedAlias.sort(SAliasComparator());
	}
}

void CVirtualFileSystem::RemoveFileSystem(const std::string& alias)
{
	std::string a = alias;
	if (!CStringUtils::EndsWith(a, "/"))
	{
		a += "/";
	}

	TFileSystemMap::const_iterator it = m_FileSystem.find(a);
	if (it == m_FileSystem.end())
	{
		m_FileSystem.erase(it);
		// TODO: remove from alias list
	}
}

bool CVirtualFileSystem::IsFileSystemExists(const std::string& alias) const
{
	return (m_FileSystem.find(alias) != m_FileSystem.end());
}

IFileSystemPtr CVirtualFileSystem::GetFileSystem(const std::string &alias)
{
	return m_FileSystem[alias];
}

IFileSystemPtr CVirtualFileSystem::GetFileSystem(const CFileInfo &path)
{
	auto a = getFileSystemAndAliasFromFileInfo(path);
	if (a.alias.empty() && a.filesystem == nullptr) return nullptr;
	return a.filesystem;
}

CFileInfo CVirtualFileSystem::GetFileInfoForPath(const CFileInfo &path)
{
	auto p = path.AbsolutePath();
	if (!p.empty() && p.at(0) != '/')
		return CFileInfo('/' + p);

	return path;
}

std::list<CVirtualFileSystem::SSortedAlias>::value_type CVirtualFileSystem::getFileSystemAndAliasFromFileInfo(const CFileInfo &path)
{
	for (auto &a : m_SortedAlias)
	{
		auto alias = a.alias;
		auto fs = a.filesystem;
		auto target = path.AbsolutePath();

		// Add preceding '/' from path and from alias
		if (!alias.empty() && alias.at(0) != '/')
			alias = '/' + alias;

		// Add preceding '/' from requested path
		if (!target.empty() && target.at(0) != '/')
			target = '/' + target;

		// Check to see if target begins with alias
		if (CStringUtils::StartsWith(target, alias) && target.length() != alias.length())
			return a;
	}

	return { "", nullptr };
}

bool CVirtualFileSystem::FileExists(const CFileInfo &filePath)
{
	auto p = getFileSystemAndAliasFromFileInfo(filePath);
	if (!p.filesystem)
		return false;

	// Remove alias from path
	const CFileInfo fileInfo(GetFileInfoForPath(filePath).AbsolutePath().substr(p.alias.size()));
	return p.filesystem->IsFileExists(fileInfo);
}

IFilePtr CVirtualFileSystem::OpenFile(const CFileInfo& filePath, IFile::FileMode mode)
{
	auto p = getFileSystemAndAliasFromFileInfo(filePath);
	if (!p.filesystem)
		return nullptr;

	// Remove alias from path
	const CFileInfo fileInfo(GetFileInfoForPath(filePath).AbsolutePath().substr(p.alias.size()));
	return p.filesystem->OpenFile(fileInfo, mode);
}

bool CVirtualFileSystem::RemoveFile(const CFileInfo &filePath)
{
	auto p = getFileSystemAndAliasFromFileInfo(filePath);
	if (!p.filesystem)
		return false;

	// Remove alias from path
	const CFileInfo fileInfo(GetFileInfoForPath(filePath).AbsolutePath().substr(p.alias.size()));
	return p.filesystem->RemoveFile(fileInfo);
}

bool CVirtualFileSystem::RenameFile(const CFileInfo &srcPath, const CFileInfo &destPath)
{
	auto p = getFileSystemAndAliasFromFileInfo(srcPath);
	if (!p.filesystem)
		return false;

	// Remove alias from path
	const CFileInfo srcFileInfo(GetFileInfoForPath(srcPath).AbsolutePath().substr(p.alias.size()));
	const CFileInfo dstFileInfo(GetFileInfoForPath(destPath).AbsolutePath().substr(p.alias.size()));
	return p.filesystem->RenameFile(srcFileInfo, dstFileInfo);
}

bool CVirtualFileSystem::CopyFile(const CFileInfo &srcPath, const CFileInfo &destPath)
{
	auto p = getFileSystemAndAliasFromFileInfo(srcPath);
	if (!p.filesystem)
		return false;

	// Remove alias from path
	const CFileInfo srcFileInfo(GetFileInfoForPath(srcPath).AbsolutePath().substr(p.alias.size()));
	const CFileInfo dstFileInfo(GetFileInfoForPath(destPath).AbsolutePath().substr(p.alias.size()));
	return p.filesystem->CopyFile(srcFileInfo, dstFileInfo);
}

bool CVirtualFileSystem::CreateFile(const CFileInfo &filePath)
{
	auto p = getFileSystemAndAliasFromFileInfo(filePath);
	if (!p.filesystem)
		return false;

	// Remove alias from path
	const CFileInfo fileInfo(GetFileInfoForPath(filePath).AbsolutePath().substr(p.alias.size()));
	return p.filesystem->CreateFile(fileInfo);
}

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
