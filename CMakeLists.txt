cmake_minimum_required(VERSION 3.10)
project(CalculatorApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#  /MDd
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

include_directories(include)

# Main
add_executable(CalculatorApp src/main.cpp src/Calculator.cpp)

# GTest
add_subdirectory(external/googletest)
enable_testing()

# Test
add_executable(CalculatorTest
    tests/CalculatorTest.cpp
    src/Calculator.cpp
)
target_include_directories(CalculatorTest PRIVATE include)
target_link_libraries(CalculatorTest gtest gtest_main)
