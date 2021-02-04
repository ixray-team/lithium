#include "FileSystem.h"

using namespace onyx;

fsize_t onyx::IFile::idGenerator = 0;

FileSystem& onyx::fs()
{
	return *FileSystem::Instance();
}

FileSystem* FileSystem::instance;

FileSystem* FileSystem::Instance()
{
	if (instance == nullptr)
		instance = new FileSystem();

	return instance;
}

FileSystem::FileSystem()
{
	vfspp::vfs_initialize();

	const std::string basePath = "./gamedata/";

	std::vector<std::string> fsFolders {
		"anims/", "configs/", "levels/", "meshes/", "scripts/",
		"shaders/", "sounds/", "spawns/", "textures/"
	};

	vfs = vfspp::vfs_get_global();

	for (const std::string& folder : fsFolders)
		vfs->AddFileSystem(folder, vfspp::IFileSystemPtr(new vfspp::CNativeFileSystem(basePath+folder)));

	vfspp::IFileSystemPtr fs_tmp(new vfspp::CMemoryFileSystem());
	vfs->AddFileSystem("tmp/", fs_tmp);
	vfs->AddFileSystem("temp/", fs_tmp);
	vfs->AddFileSystem("memory/", fs_tmp);
}

onyx::File FileSystem::open(std::string path, FileOpenMode mode, FileCreateMode create)
{
	vfspp::IFile::FileMode vfsMode = vfspp::IFile::In;

	vfspp::CFileInfo fileInfo = vfspp::CFileInfo(path);

	bool fileExists = vfs->FileExists(fileInfo);

	switch (mode)
	{
	case onyx::FileOpenMode::Read:
	case onyx::FileOpenMode::ReadBinary:
		vfsMode = vfspp::IFile::In;
		break;
	case onyx::FileOpenMode::ReadWrite:
	case onyx::FileOpenMode::ReadWriteBinary:
		vfsMode = vfspp::IFile::ReadWrite;
		break;
	}

	if (fileExists && create == FileCreateMode::FailIfExists)
		throw new std::exception((std::string("File ")+path+" exists").c_str());

	if (!fileExists && create == FileCreateMode::FailIfNotExist)
		throw new std::exception((std::string("File ") + path + " doesn't exist").c_str());

	if (fileExists)
		vfsMode = (vfspp::IFile::FileMode)(vfsMode | vfspp::IFile::Append);

	vfspp::IFilePtr fptr = vfs->OpenFile(fileInfo, vfsMode);

	return File(new _File(fptr));
}

bool FileSystem::exists(std::string path)
{
	return vfs->FileExists(path);
}

// -- File wrapper impl
onyx::fsize_t FileSystem::_File::Size()
{
	return file->Size();
}

bool FileSystem::_File::IsReadOnly() const
{
	return file->IsReadOnly();
}

void FileSystem::_File::Open(FileMode mode)
{
	file->Open((int)mode);
}

void FileSystem::_File::Close()
{
	file->Close();
}

bool FileSystem::_File::IsOpened() const
{
	return file->IsOpened();
}

onyx::fsize_t FileSystem::_File::Seek(fsize_t offset, Origin origin)
{
	return file->Seek(offset, (vfspp::IFile::Origin)origin);
}

onyx::fsize_t FileSystem::_File::Tell()
{
	return file->Tell();
}

onyx::fsize_t FileSystem::_File::Read(unsigned char* buffer, fsize_t size)
{
	return file->Read(buffer, size);
}

onyx::fsize_t FileSystem::_File::Write(const unsigned char* buffer, fsize_t size)
{
	return file->Write(buffer, size);
}