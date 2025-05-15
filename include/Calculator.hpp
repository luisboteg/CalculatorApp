#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <vector>
#include <string>

/**
 * @brief Enum to define arithmetic operations
 */
// Can be removed
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

    /*
    /**
     * @brief Evaluates a math expression string using muParser
     * @param expression A string containing the math expression (e.g. "5 + 3 * 2")
     * @return Result of the evaluated expression
     *
    double evaluate(const std::string& expression);
    */

    /**
     * @brief Print operation history
     */
    void printHistory() const;
    /**
     * @brief Save operation history to a file
     * @param filename File path
     */
    void saveToFile(const std::string& filename) const;

    /**
     * @brief Load operation history from a file
     * @param filename File path
     */
    void loadFromFile(const std::string& filename);

    /**
     * @brief Print filtered entries
     * @param even Show even values
     * @param odd Show odd values
     * @param op Optional operation type to filter
     */
    void filterAndPrint(bool even, bool odd, Operation* op = nullptr) const;

    const std::vector<NumberInfo>& getHistory() const;


private:
    std::vector<NumberInfo> history;
    int current_order;

    void addToHistory(double value, const std::string& desc);
    bool isEven(double num);
};

#endif // CALCULATOR_HPP
