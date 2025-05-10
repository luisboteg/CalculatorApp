#include "Calculator.hpp"
#include <gtest/gtest.h>
#include <fstream>
#include <cstdio>

// Tests for each arithmetic operation
TEST(OperationTest, Addition) 
{
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.compute(3, 4, Operation::ADDITION), 7);
}

TEST(OperationTest, Subtraction) 
{
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.compute(10, 4, Operation::SUBTRACTION), 6);
}

TEST(OperationTest, Multiplication) 
{
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.compute(3, 5, Operation::MULTIPLICATION), 15);
}

TEST(OperationTest, Division) 
{
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.compute(8, 2, Operation::DIVISION), 4);
}

// Division by zero should throw an exception
TEST(OperationTest, DivisionByZeroThrows) 
{
    Calculator calc;
    EXPECT_THROW(calc.compute(5, 0, Operation::DIVISION), std::invalid_argument);
}

// Verify that saved history can be reloaded and matches the original
TEST(HistoryTest, SaveAndReloadHistoryConsistency) 
{
    Calculator calc;
    calc.compute(5, 3, Operation::ADDITION);
    calc.compute(6, 2, Operation::DIVISION);

    const std::string filename = "test_history_temp.txt";
    calc.saveToFile(filename);

    Calculator reloaded;
    reloaded.loadFromFile(filename);

    const auto& hist1 = calc.getHistory();
    const auto& hist2 = reloaded.getHistory();

    ASSERT_EQ(hist1.size(), hist2.size());
    for (size_t i = 0; i < hist1.size(); ++i) 
    {
        EXPECT_EQ(hist1[i].value, hist2[i].value);
        EXPECT_EQ(hist1[i].is_even, hist2[i].is_even);
        EXPECT_EQ(hist1[i].description, hist2[i].description);
    }

    std::remove(filename.c_str());
}

// Ensure that even numbers are correctly identified and counted
TEST(FilterTest, OnlyEvenNumbers) {
    Calculator calc;
    calc.compute(4, 2, Operation::MULTIPLICATION); // 8
    calc.compute(3, 3, Operation::ADDITION);       // 6

    int even_count = 0;
    for (const auto& entry : calc.getHistory()) 
    {
        if (entry.is_even)
        {
            even_count++;
        }
    }

    ASSERT_EQ(even_count, 4); // At least result or operands are even
}

// Ensure that odd numbers are correctly identified and counted
TEST(FilterTest, OnlyOddNumbers) 
{
    Calculator calc;
    calc.compute(1, 3, Operation::ADDITION); // 4

    int odd_count = 0;
    for (const auto& entry : calc.getHistory()) 
    {
        if (!entry.is_even) odd_count++;
    }

    ASSERT_GE(odd_count, 2); // 1 and 3 are odd
}

// Check that the history includes a subtraction operation description
TEST(FilterTest, OperationFilterMatchesSubtraction) 
{
    Calculator calc;
    calc.compute(9, 4, Operation::SUBTRACTION);

    int match_count = 0;
    for (const auto& entry : calc.getHistory()) 
    {
        if (entry.description.find("-") != std::string::npos) match_count++;
    }

    ASSERT_GT(match_count, 0);
}

// Validate that the description string is correctly formatted
TEST(DescriptionTest, DescriptionCorrectness) 
{
    Calculator calc;
    double a = 7.0, b = 3.0;
    double result = calc.compute(a, b, Operation::SUBTRACTION);

    const auto& history = calc.getHistory();
    const auto& last = history.back();

    std::ostringstream oss;
    oss << a << " - " << b << " = " << result;

    EXPECT_EQ(last.description, oss.str());
}