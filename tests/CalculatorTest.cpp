#include "Calculator.hpp"
#include <gtest/gtest.h>

TEST(CalculatorTest, Addition) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.compute(3, 4, Operation::ADDITION), 7);
}

TEST(CalculatorTest, Subtraction) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.compute(10, 4, Operation::SUBTRACTION), 6);
}

TEST(CalculatorTest, Multiplication) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.compute(3, 5, Operation::MULTIPLICATION), 15);
}

TEST(CalculatorTest, Division) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.compute(8, 2, Operation::DIVISION), 4);
}

TEST(CalculatorTest, DivisionByZeroThrows) {
    Calculator calc;
    EXPECT_THROW(calc.compute(5, 0, Operation::DIVISION), std::invalid_argument);
}
