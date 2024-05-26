#pragma once

#include <filesystem>

class FileWriter
{
public:
    explicit FileWriter(std::filesystem::path path) noexcept;
    void Write(const char *buf, int len) noexcept;
    void WriteAt(const char *buf, int len, size_t offset) noexcept;
    size_t GetOffset() const noexcept { return mOffset; }
    ~FileWriter();

private:
    std::filesystem::path mPath;
    int mFd;
    size_t mOffset;
};