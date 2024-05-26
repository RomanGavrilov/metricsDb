#pragma once

// prometheus format
// metric_name{label1="value1", label2="value2", ...} value

template <typename T>
struct SingleMetric
{
    int name;
    std::vector<int> labels;
    std::vector<T> values;
};

typedef SingleMetric<int> IntMetric;
typedef SingleMetric<float> FloatMetric;
typedef SingleMetric<double> DoubleMetric;
typedef SingleMetric<std::string> StringMetric;
typedef SingleMetric<bool> BoolMetric;

struct Metrics
{
    std::vector<IntMetric> intMetrics;
    std::vector<FloatMetric> floatMetrics;
    std::vector<DoubleMetric> doubleMetrics;
    std::vector<StringMetric> stringMetrics;
    std::vector<BoolMetric> boolMetrics;
};
