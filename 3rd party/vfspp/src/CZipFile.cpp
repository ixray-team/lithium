//
//  CZipFile.cpp
//  vfspp
//
//  Created by Yevgeniy Logachev on 6/23/16.
//
//

#include "CZipFile.h"
#include "miniz.h"
#include <sys/stat.h>
#include <cstring>
#include "CStringUtilsVFS.h"
#include <dirent.h>

#ifdef min
#undef min
#endif

using namespace vfspp;

// *****************************************************************************
// Constants
// *****************************************************************************

CZip::TEntriesMap CZip::s_Entries;

// *****************************************************************************
// Public Methods
// *****************************************************************************

CZip::CZip(const std::string& zipPath)
	: m_FileName(zipPath)
{
	m_ZipArchive = static_cast<mz_zip_archive*>(malloc(sizeof(struct mz_zip_archive_tag)));
	memset(m_ZipArchive, 0, sizeof(struct mz_zip_archive_tag));

	mz_bool status = mz_zip_reader_init_file((mz_zip_archive*)m_ZipArchive, zipPath.c_str(), 0);
	if (!status)
	{
		VFS_LOG("Cannot open zip file: %s\n", zipPath.c_str());
		assert("Cannot open zip file" && false);
	}

	for (mz_uint i = 0; i < mz_zip_reader_get_num_files((mz_zip_archive*)m_ZipArchive); i++)
	{
		mz_zip_archive_file_stat file_stat;
		if (!mz_zip_reader_file_stat((mz_zip_archive*)m_ZipArchive, i, &file_stat))
		{
			VFS_LOG("Cannot read entry with index: %d from zip archive", i, zipPath.c_str());
			continue;
		}

		s_Entries[file_stat.m_filename] = std::make_tuple(file_stat.m_file_index, file_stat.m_uncomp_size);
	}
}

CZip::~CZip()
{
	free(m_ZipArchive);
}

bool CZip::FindFile(const std::string &fileName, uint32_t &index, uint64_t &size) const
{
	const auto it = s_Entries.find(fileName);
	if (it == s_Entries.end()) {
		return false;
	}

	index = std::get<0>(it->second);
	size = std::get<1>(it->second);

	return true;
}

bool CZip::ReadFile(uint32_t index, uint8_t *data, size_t offset, size_t size) const
{
	return mz_zip_reader_extract_to_mem_offset_no_alloc((mz_zip_archive*)m_ZipArchive,
		index,
		offset,
		data,
		size,
		0) >= 0;
}

const std::string& CZip::FileName() const
{
	return m_FileName;
}

bool CZip::IsReadOnly() const
{
	struct stat fileStat;
	if (stat(FileName().c_str(), &fileStat) < 0) {
		return false;
	}
	return fileStat.st_mode & S_IWUSR;
}


// *****************************************************************************
// Public Methods
// *****************************************************************************

CZipFile::CZipFile(const CFileInfo& fileInfo, CZipPtr zipFile)
	: m_ZipArchive(zipFile)
	, m_FileInfo(fileInfo)
	, m_IsReadOnly(true)
	, m_IsOpened(false)
	, m_HasChanges(false)
	, m_SeekPos(0)
	, m_Mode(0)
{
	assert(m_ZipArchive && "Cannot init zip file from empty zip archive");
}

CZipFile::~CZipFile()
{

}

const CFileInfo& CZipFile::FileInfo() const
{
	return m_FileInfo;
}

uint64_t CZipFile::Size()
{
	if (IsOpened())
	{
		return m_Size;
	}

	return 0;
}

bool CZipFile::IsReadOnly() const
{
	assert(m_ZipArchive && "Zip archive is epty");
	return m_ZipArchive && m_ZipArchive->IsReadOnly() && m_IsReadOnly;
}

void CZipFile::Open(int mode)
{
	if (mode & Out ||
		mode & Append ||
		mode & Truncate) {
		VFS_LOG("Files from zip can be opened in read only mode");
		return;
	}

	if (!FileInfo().IsValid() ||
		IsOpened() && m_Mode == mode ||
		!m_ZipArchive)
	{
		return;
	}

	std::string absPath = FileInfo().AbsolutePath();
	if (CStringUtils::StartsWith(absPath, "/"))
	{
		absPath = absPath.substr(1, absPath.length() - 1);
	}

	if (!m_ZipArchive->FindFile(absPath, m_Index, m_Size))
	{
		VFS_LOG("Cannot open file: %s from zip: %s", absPath.c_str(), m_ZipArchive->FileName().c_str());
		return;
	}

	m_Mode = mode;
	m_IsReadOnly = true;
	m_SeekPos = 0;

	m_IsOpened = true;
}

void CZipFile::Close()
{
	m_IsOpened = false;
}

bool CZipFile::IsOpened() const
{
	return m_IsOpened;
}

uint64_t CZipFile::Seek(uint64_t offset, Origin origin)
{
	if (!IsOpened())
	{
		return 0;
	}

	if (origin == Begin)
	{
		m_SeekPos = offset;
	}
	else if (origin == End)
	{
		m_SeekPos = Size() - offset;
	}
	else
	{
		m_SeekPos += offset;
	}
	m_SeekPos = std::min(m_SeekPos, Size() - 1);

	return Tell();
}

uint64_t CZipFile::Tell()
{
	return m_SeekPos;
}

uint64_t CZipFile::Read(uint8_t* buffer, uint64_t size)
{
	if (!IsOpened())
	{
		return 0;
	}

	// check offsets
	if (m_SeekPos + size > m_Size || size > m_Size)
	{
		return 0;
	}

	// read file
	if (m_ZipArchive->ReadFile(m_Index, buffer, m_SeekPos, size))
	{
		m_SeekPos += size;
		return true;
	}

	return 0;
}

uint64_t CZipFile::Write(const uint8_t* buffer, uint64_t size)
{
	// Operation not supported
	return -1;
}

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
