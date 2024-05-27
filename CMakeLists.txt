cmake_minimum_required(VERSION 3.10)

project(MetricsDb)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

add_executable(metricsDb main.cpp file-writer.cpp labels-writer.cpp metrics-db.cpp)

enable_testing()
add_subdirectory(tests)
