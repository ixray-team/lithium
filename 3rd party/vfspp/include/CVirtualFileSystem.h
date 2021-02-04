//
//  CVirtualFileSystem.h
//  vfspp
//
//  Created by Yevgeniy Logachev on 6/23/16.
//
//

#ifndef CVIRTUALFILESYSTEM_H
#define CVIRTUALFILESYSTEM_H

#include "IFileSystem.h"
#include "IFile.h"

#ifdef _WIN32
#undef CreateFile
#undef CopyFile
#endif

namespace vfspp
{
CLASS_PTR(IFile)
CLASS_PTR(IFileSystem)
CLASS_PTR(CVirtualFileSystem)
    
extern void vfs_initialize();
extern void vfs_shutdown();
extern CVirtualFileSystemPtr vfs_get_global();
    
class CVirtualFileSystem final
{
public:
    typedef std::list<IFileSystemPtr> TFileSystemList;
    typedef std::unordered_map<std::string, IFileSystemPtr> TFileSystemMap;
    
    struct SSortedAlias
    {
        std::string alias;
        IFileSystemPtr filesystem;
        
        SSortedAlias(const std::string& a,
                     IFileSystemPtr fs)
        : alias(a)
        , filesystem(fs)
        {}
    };
    typedef std::list<SSortedAlias> TSortedAliasList;


    CVirtualFileSystem();
    ~CVirtualFileSystem();
    
    /*
     * Register new filesystem. Alias is base prefix to file access.
     * For ex. registered filesystem has base path '/home/media', but registered
     * with alias '/', so it possible to access files with path '/filename'
     * instead of '/home/media/filename
     */
    void AddFileSystem(const std::string& alias, IFileSystemPtr filesystem);
    
    /*
     * Remove registered filesystem
     */
    void RemoveFileSystem(const std::string& alias);
    
    /*
     * Check if filesystem with 'alias' registered
     */
    bool IsFileSystemExists(const std::string& alias) const;
    
    /*
     * Get filesystem with 'alias'
     */
    IFileSystemPtr GetFileSystem(const std::string& alias);

	/*
	 * Get file system from a path
	 */
	IFileSystemPtr GetFileSystem(const CFileInfo &path);
    
    /*
     * Iterate over all registered filesystems and find first ocurrences of file
     */
    bool FileExists(const CFileInfo& filePath);
    
    /*
     * Iterate over all registered filesystems and find first ocurrences of file, then creates it
     */
    bool CreateFile(const CFileInfo& filePath);
    
    /*
     * Iterate over all registered filesystems and find first ocurrences of file, then opens it
     */
    IFilePtr OpenFile(const CFileInfo& filePath, IFile::FileMode mode);
    
    /*
     * Iterate over all registered filesystems and find first ocurrences of file, then removes it
     */
    bool RemoveFile(const CFileInfo& filePath);
    
    /*
     * Iterate over all registered filesystems and find first ocurrences of file, then renames it
     */
    bool RenameFile(const CFileInfo& srcPath, const CFileInfo& destPath);
    
    /*
     * Iterate over all registered filesystems and find first ocurrences of file, then copies it
     */
    bool CopyFile(const CFileInfo& srcPath, const CFileInfo& destPath);

private:
	/*
	 * Normalize path
	 */
	static CFileInfo GetFileInfoForPath(const CFileInfo& path);

    /*
     * Get filesystem with 'alias'
     */
    TSortedAliasList::value_type getFileSystemAndAliasFromFileInfo(const CFileInfo& path);

    TFileSystemMap m_FileSystem;
    TSortedAliasList m_SortedAlias;
};
    
}; // namespace vfspp

#endif /* CVIRTUALFILESYSTEM_H */
