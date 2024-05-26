#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "metric.hpp"
#include "labels-writer.hpp"

class MetricsDb
{
public:
    MetricsDb(const std::string dbPath);
    void SaveMetric(std::string prometheusMetric);

private:
    std::string mPath;
    LabelsWriter mLabelsWriter;

private:
    MetricsDb() = delete;
    MetricsDb(const MetricsDb &) = delete;
    void WriteHeader();
};
