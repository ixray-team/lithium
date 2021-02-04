#pragma once

#include <string>
#include <fstream>
#include "onyx/noncopyable.hpp"

#include <vfspp/VFS.h>
#include <vfspp/CVirtualFileSystem.h>
#include <vfspp/CNativeFileSystem.h>
#include <vfspp/IFile.h>
#include <vfspp/CNativeFile.h>
#include <vfspp/CMemoryFileSystem.h>

#include "IFile.h"

namespace onyx
{
	using File = std::shared_ptr<onyx::IFile>;

	enum class FileOpenMode
	{
		// Read-only
		Read,

		// ReadWrite
		ReadWrite,

		// Read only (u8 mode)
		ReadBinary,

		// ReadWrite (u8 mode)
		ReadWriteBinary
	};

	enum class FileCreateMode
	{
		// Create if not exists. If exists - overwrite
		EmptyIfNotExists,

		// Throw if exists
		FailIfExists,

		// Throw if not exists
		FailIfNotExist,
	};

	class FileSystem : noncopyable
	{
	public:
		static FileSystem* Instance();

	private:
		FileSystem();
		static FileSystem* instance;

	public:
		File open(std::string path, FileOpenMode mode = FileOpenMode::Read, FileCreateMode create = FileCreateMode::EmptyIfNotExists);
		bool exists(std::string path);

	private:
		vfspp::CVirtualFileSystemPtr vfs;

		class _File : public IFile
		{
		friend class FileSystem;

		private:
			vfspp::IFilePtr file;

			_File(vfspp::IFilePtr parent) : IFile(), file(parent) {};

		public:
			fsize_t Size() override;
			bool IsReadOnly() const override;
			void Open(FileMode mode) override;
			void Close() override;
			bool IsOpened() const override;
			fsize_t Seek(fsize_t offset, Origin origin) override;
			fsize_t Tell() override;
			fsize_t Read(unsigned char* buffer, fsize_t size) override;
			fsize_t Write(const unsigned char* buffer, fsize_t size) override;
		};
	};

	extern FileSystem& fs();
}