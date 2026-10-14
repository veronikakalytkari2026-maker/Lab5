
cmake_minimum_required(VERSION 3.20)

project(Lab5Tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(GTest REQUIRED)

add_executable(test_05_1
    tests/test_05_1.cpp
)

target_link_libraries(test_05_1
    PRIVATE
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_05_1)