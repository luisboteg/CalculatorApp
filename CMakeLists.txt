cmake_minimum_required(VERSION 3.10)
project(CalculatorApp)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(CalculatorApp src/main.cpp src/Calculator.cpp)

# Tests
enable_testing()
add_executable(CalculatorTest tests/CalculatorTest.cpp src/Calculator.cpp)
target_include_directories(CalculatorTest PRIVATE include)
find_package(GTest REQUIRED)
target_link_libraries(CalculatorTest GTest::gtest GTest::gtest_main)
add_test(NAME CalculatorTest COMMAND CalculatorTest)
