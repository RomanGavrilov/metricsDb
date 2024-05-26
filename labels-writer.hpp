#include <filesystem>
#include <string>
#include "file-writer.hpp"

class LabelsDataWriter
{
public:
    LabelsDataWriter(std::filesystem::path dataPath);
    void Write(const std::string &label);
    size_t GetOffset() const noexcept { return mWriter.GetOffset(); }

private:
    void WriteHeader();

private:
    FileWriter mWriter;
};

class LabelsIndexWriter
{
public:
    LabelsIndexWriter(std::filesystem::path indexPath);
    void Write(size_t hash);
    size_t GetOffset() const noexcept { return mWriter.GetOffset(); }

private:
    void WriteHeader();

private:
    FileWriter mWriter;
};

class LabelsWriter
{

public:
    LabelsWriter(const std::filesystem::path &dbPath);
    void Write(const std::string &label);
    size_t DataOffset() const noexcept { return mDataWriter.GetOffset(); }
    size_t IndexOffset() const noexcept { return mIndexWriter.GetOffset(); }

private:
    LabelsIndexWriter mIndexWriter;
    LabelsDataWriter mDataWriter;
};
