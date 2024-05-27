#include "labels-writer.hpp"
#include "header.hpp"

namespace
{
    constexpr int TABLE_SIZE = 20e6;
    constexpr int MAGIC = 0x74696e79; // tiny
    constexpr int VERSION = 1;

    size_t hashString(const std::string &str)
    {
        std::hash<std::string> hash_fn;
        return hash_fn(str) % TABLE_SIZE;
    }

    namespace fs = std::filesystem;
}

// wrapper for writing labels
LabelsWriter::LabelsWriter(const std::filesystem::path &dbPath)
    : mIndexWriter(dbPath.string() + ".lindex"), mDataWriter(dbPath.string() + ".ldata")
{
}

void LabelsWriter::Write(const std::string &label)
{
    mIndexWriter.Write(hashString(label));
    mDataWriter.Write(label);
}

// data writer
LabelsDataWriter::LabelsDataWriter(std::filesystem::path dataPath)
    : mWriter(dataPath)
{
    WriteHeader();
}

void LabelsDataWriter::WriteHeader()
{
    Header header{MAGIC, VERSION, mWriter.GetOffset()};
    mWriter.WriteAt(reinterpret_cast<const char *>(&header), sizeof(header), 0);
}

void LabelsDataWriter::Write(const std::string &label)
{
    mWriter.Write(label.c_str(), label.size());
    WriteHeader();
}

// index writer
LabelsIndexWriter::LabelsIndexWriter(std::filesystem::path indexPath)
    : mWriter(indexPath)
{
    WriteHeader();
}

void LabelsIndexWriter::WriteHeader()
{
    Header header{MAGIC, VERSION, mWriter.GetOffset()};
    mWriter.WriteAt(reinterpret_cast<const char *>(&header), sizeof(header), 0);
}

void LabelsIndexWriter::Write(size_t hash)
{
    mWriter.Write(reinterpret_cast<const char *>(&hash), sizeof(hash));
    WriteHeader();
}
