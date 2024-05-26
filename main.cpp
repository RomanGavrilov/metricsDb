#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>
#include <thread>
#include "metrics-db.hpp"


void ValidateArgs(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <db_path>" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void PrintMemoryUsage()
{
    std::ifstream statusFile("/proc/self/status");
    std::string line;

    while (std::getline(statusFile, line))
    {
        if (line.compare(0, 6, "VmSize") == 0 || line.compare(0, 5, "VmRSS") == 0)
        {
            std::cout << line << std::endl;
        }
    }
}

int main(int argc, char **argv)
{
    ValidateArgs(argc, argv);
 
    MetricsDb metrics(argv[1]);
    PrintMemoryUsage();

    const std::string prometheus_metrics_file = "/home/rga/algorithms/prometheus-metrics.txt";
    std::ifstream file(prometheus_metrics_file);

    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
        if (line[0] == '#')
            continue;

        metrics.SaveMetric(line);
        PrintMemoryUsage();
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }

    return EXIT_SUCCESS;
}
