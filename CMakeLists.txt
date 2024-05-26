cmake_minimum_required(VERSION 3.16)
project(TinyMetrics)

set(CMAKE_CXX_STANDARD 17)

# Set the build type to Debug
set(CMAKE_BUILD_TYPE Debug)

add_executable(tiny_metrics main.cpp metrics-db.cpp file-writer.cpp labels-writer.cpp)
