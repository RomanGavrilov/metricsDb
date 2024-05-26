#include <fcntl.h>
#include <iostream>
#include <unistd.h>

#include "header.hpp"
#include "file-writer.hpp"

FileWriter::FileWriter(std::filesystem::path path) noexcept
    : mPath(path), mFd(-1), mOffset(sizeof(Header))
{
    mFd = open(mPath.c_str(), O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    if (mFd == -1)
    {
        std::cerr << "Failed to open file: " << mPath << std::endl;
        exit(EXIT_FAILURE);
    }
}

void FileWriter::WriteAt(const char *buf, int len, size_t offset) noexcept
{
    int totalWritten = 0;
    int currentOffset = offset;

    while (len > 0)
    {
        int n = TEMP_FAILURE_RETRY(pwrite64(mFd, buf + currentOffset, len, currentOffset));

        if (n < 0)
        {
            std::cerr << "Failed to write to file: " << errno << std::endl;
        }

        len -= n;
        totalWritten += n;
        currentOffset += n;
    }
}

void FileWriter::Write(const char *buf, int len) noexcept
{
    int totalWritten = 0;
    int currentOffset = 0;

    while (len > 0)
    {
        int n = TEMP_FAILURE_RETRY(pwrite64(mFd, buf + currentOffset, len, mOffset + currentOffset));

        if (n < 0)
        {
            std::cerr << "Failed to write to file: " << errno << std::endl;
        }

        len -= n;
        totalWritten += n;
        currentOffset += n;
    } 

    mOffset += totalWritten;
}

FileWriter::~FileWriter()
{
    if (mFd != -1)
    {
        close(mFd);
    }
}
