#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <vector>
#include <string>
#include <memory>

/**
 * @brief Enum to define arithmetic operations
 */
enum class Operation {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
};

/**
 * @brief Structure to store information about a number
 */
struct NumberInfo {
    double value;
    bool is_even;
    int order;
    std::string description;
};

/**
 * @brief Calculator class to perform operations and maintain history
 */
class Calculator {
public:
    Calculator();

    /**
     * @brief Perform an arithmetic operation
     * @param a First operand
     * @param b Second operand
     * @param op Operation type
     * @return Result of the operation
     */
    double compute(double a, double b, Operation op);

    /**
     * @brief Print operation history
     */
    void printHistory() const;

    /**
     * @brief Get history data
     */
    const std::vector<NumberInfo>& getHistory() const;

private:
    std::vector<NumberInfo> history;
    int current_order;

    void addToHistory(double value, const std::string& desc);
    bool isEven(double num);
};

#endif // CALCULATOR_HPP
