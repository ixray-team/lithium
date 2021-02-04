#pragma once
#include <memory>

namespace onyx
{
    using fsize_t = unsigned long;

    class IFile
    {
    public:
        /*
         * Seek modes
         */
        enum Origin
        {
            Begin,
            End,
            Set
        };

        /*
         * Open file mode
         */
        enum class FileMode
        {
            In = 0x01,
            Out = 0x02,
            ReadWrite = In | Out,
            Append = 0x04,
            Truncate = 0x08
        };

    protected:
        fsize_t id;
        static fsize_t idGenerator;

    public:
        IFile() : id(idGenerator++) {};
        virtual ~IFile() = default;

        virtual fsize_t Size() = 0;
        virtual bool IsReadOnly() const = 0;

        virtual void Open(FileMode mode) = 0;
        virtual void Close() = 0;

        virtual bool IsOpened() const = 0;

        virtual fsize_t Seek(fsize_t offset, Origin origin) = 0;
        virtual fsize_t Tell() = 0;
        virtual fsize_t Read(unsigned char* buffer, fsize_t size) = 0;
        virtual fsize_t Write(const unsigned char* buffer, fsize_t size) = 0;

        /*
         * Templated alternative to Read
         */
        template<typename T>
        bool Read(T& value)
        {
            return (Read(&value, sizeof(value)) == sizeof(value));
        }

        /*
         * Templated alternative to Write
         */
        template<typename T>
        fsize_t Write(const T& value)
        {
            return (Write(&value, sizeof(value)) == sizeof(value));
        }

        inline bool operator==(const IFile& other)
        {
            return other.id == id;
        }
    };

    inline bool operator ==(std::shared_ptr<IFile> f1, std::shared_ptr<IFile> f2)
    {
        if (!f1 || !f2)
        {
            return false;
        }

        return *f1 == *f2;
    }
}