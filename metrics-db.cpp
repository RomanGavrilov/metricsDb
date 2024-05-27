#include <filesystem>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <charconv>
#include <cmath>
#include <algorithm>

#include "metrics-db.hpp"

namespace
{
    constexpr uint32_t MAGIC = 0x74696e79; // tiny
    constexpr uint32_t VERSION = 1;

    namespace fs = std::filesystem;
    void CreateBinary(const std::filesystem::path &dbPath)
    {
        std::error_code ec;
        const auto parentPath = fs::path(dbPath).parent_path();

        fs::create_directories(parentPath, ec);
        if (ec)
        {
            std::cerr << "Failed to create db directory: " << ec.message() << std::endl;
            exit(EXIT_FAILURE);
        }

        std::ofstream file(dbPath);
        if (!file)
        {
            std::cerr << "Failed to create the file: " << dbPath << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    int Read(int fd, char *buf, int len, size_t offset) noexcept
    {
        int totalRead = 0;
        int currentOffset = 0;

        while (len > 0)
        {
            int n = TEMP_FAILURE_RETRY(pread64(fd, buf + offset, len, offset));

            if (n == 0)
            {
                totalRead += n;
                break;
            }

            if (n < 0)
            {
                return errno;
            }

            len -= n;
            totalRead += n;
            currentOffset += n;
        }

        return totalRead;
    }

    bool TryConvertToDouble(const char *startPtr, const char *endPtr, double &value)
    {
        auto [ptr, ec] = std::from_chars(startPtr, endPtr, value);
        return (ec == std::errc() && ptr == endPtr);
    }

    bool IsInteger(const double &val)
    {
        // TODO check bigint boundaries
        return std::floor(val) == val;
    }

    const char *ws = " \t\n\r\f\v";

    // trim from end of string (right)
    inline std::string &rtrim(std::string &s, const char *t = ws)
    {
        s.erase(s.find_last_not_of(t) + 1);
        return s;
    }

    // trim from beginning of string (left)
    inline std::string &ltrim(std::string &s, const char *t = ws)
    {
        s.erase(0, s.find_first_not_of(t));
        return s;
    }

    // trim from both ends of string (right then left)
    inline std::string &trim(std::string &s, const char *t = ws)
    {
        return ltrim(rtrim(s, t), t);
    }

}

MetricsDb::MetricsDb(std::string dbPath) : mPath(std::move(dbPath)), mLabelsWriter(mPath)
{
}

void MetricsDb::SaveMetric(std::string prometheusMetric)
{
    size_t labelStart = prometheusMetric.find('{');
    if (labelStart == std::string_view::npos)
    {
        labelStart = prometheusMetric.find(' ');
    }

    std::string_view metricType{prometheusMetric.data(), labelStart};

    size_t labelEnd = prometheusMetric.find('}', labelStart);

    if (labelEnd == std::string_view::npos)
    {
        labelEnd = labelStart;
    }

    std::string_view labels{prometheusMetric.data() + labelStart, labelEnd - labelStart + 1};

    mLabelsWriter.Write(std::string{labels});

    // struct MetricData
    // {
    //     int labelId;
    //     int mTypeId;
    // } mData{-1, -1};

    // mData.labelId = labelsContainer.ResolveId(labelStr);
    // mData.mTypeId = typesContainer.ResolveId(metricTypeStr);

    // size_t valueStart = labelEnd != std::string_view::npos ? labelEnd + 1 : labelStart;
    // valueStart = line.find_first_not_of(" \t", valueStart); // check std::string_view::npos

    // size_t valueEnd = line.find(' ', valueStart);
    // std::string_view valueStr = line.substr(valueStart, valueEnd - valueStart);

    // // todo throw or log bad metric format

    // double value;
    // if (!TryConvertToDouble(valueStr.data(), valueStr.data() + valueStr.size(), value))
    // {
    //     mMetrics.StringMetrics.emplace_back(mData.mTypeId, mData.labelId, std::string{valueStr});
    // }
    // else if (IsInteger(value))
    // {
    //     mMetrics.IntMetrics.emplace_back(mData.mTypeId, mData.labelId, static_cast<uint64_t>(value));
    // }
    // else
    // {
    //     mMetrics.FloatMetrics.emplace_back(mData.mTypeId, mData.labelId, value);
    // }
}

// Path: db.hpp