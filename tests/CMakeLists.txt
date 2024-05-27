project(Tests)

set(GTEST_SOURCE_DIR "${CMAKE_SOURCE_DIR}/lib/googletest")

add_subdirectory(${GTEST_SOURCE_DIR} ${CMAKE_BINARY_DIR}/googletest-build)

include_directories(${GTEST_SOURCE_DIR}/googletest/include)
include_directories(${GTEST_SOURCE_DIR}/googlemock/include)

set(TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/test1.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test2.cpp
)

foreach(test_source ${TEST_SOURCES})
    get_filename_component(test_name ${test_source} NAME_WE)
    add_executable(${test_name} ${test_source})
    target_link_libraries(${test_name} gtest gtest_main)
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()
