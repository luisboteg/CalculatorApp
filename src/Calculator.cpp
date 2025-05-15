#include "Calculator.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
//#include <muParser> ToAdd

/**
 * @brief Constructor initializes the order counter.
 */
Calculator::Calculator() : current_order(1) {}

double Calculator::compute(double a, double b, Operation op) {
    double result = 0.0;
    std::ostringstream desc;

    switch (op) {
        case Operation::ADDITION:
            result = a + b;
            desc << a << " + " << b << " = " << result;
            break;
        case Operation::SUBTRACTION:
            result = a - b;
            desc << a << " - " << b << " = " << result;
            break;
        case Operation::MULTIPLICATION:
            result = a * b;
            desc << a << " * " << b << " = " << result;
            break;
        case Operation::DIVISION:
            if (b == 0.0)
            {
                throw std::invalid_argument("Division by zero");
            }
            result = a / b;
            desc << a << " / " << b << " = " << result;
            break;
        default:
            std::cout << "Unknown operation" << std::endl;
    }

    // Store operands and result in history
    addToHistory(a, "Operand A");
    addToHistory(b, "Operand B");
    addToHistory(result, desc.str());

    return result;
}

/* TODO
double Calculator::evaluate(const std::string& expression) {
    mu::Parser parser;
    parser.SetExpr(expression);
    double result = parser.Eval();

    addToHistory(result, expression + " = " + std::to_string(result));
    return result;
}
*/

void Calculator::addToHistory(double value, const std::string& desc) {
    NumberInfo info;
    info.value = value;
    info.is_even = isEven(value);
    info.order = current_order++;
    info.description = desc;
    history.push_back(info);
}

bool Calculator::isEven(double num) {
    return static_cast<int>(num) % 2 == 0;
}

void Calculator::printHistory() const {
    std::cout <<"\n--- Operation History ---\n";
    for (const auto& entry : history) {
        std::cout << "Order: " << entry.order
                  << ", Value: " << entry.value
                  << ", Even: " << (entry.is_even ? "Yes" : "No")
                  << ", Desc: " << entry.description << std::endl;
    }
}

void Calculator::saveToFile(const std::string& filename) const {
    std::ofstream ofs(filename);
    for (const auto& entry : history) {
        ofs << entry.order << "," << entry.value << "," << entry.is_even << "," << entry.description << "\n";
    }
}

void Calculator::loadFromFile(const std::string& filename) {
    std::ifstream ifs(filename);
    std::string line;
    history.clear();
    current_order = 1;
    while (std::getline(ifs, line)) {
        std::istringstream iss(line);
        std::string token;
        NumberInfo info;
        std::getline(iss, token, ','); info.order = std::stoi(token);
        std::getline(iss, token, ','); info.value = std::stod(token);
        std::getline(iss, token, ','); info.is_even = (token == "1");
        std::getline(iss, token); info.description = token;
        history.push_back(info);
        current_order = std::max(current_order, info.order + 1);
    }
}

void Calculator::filterAndPrint(bool even, bool odd, Operation* op) const {
    for (const auto& entry : history) {
        if ((even && entry.is_even) || (odd && !entry.is_even)) {
            if (op) {
                if (entry.description.find("+") == std::string::npos && *op == Operation::ADDITION) continue;
                if (entry.description.find("-") == std::string::npos && *op == Operation::SUBTRACTION) continue;
                if (entry.description.find("*") == std::string::npos && *op == Operation::MULTIPLICATION) continue;
                if (entry.description.find("/") == std::string::npos && *op == Operation::DIVISION) continue;
            }
            std::cout << "Order: " << entry.order
                << ", Value: " << entry.value
                << ", Even: " << (entry.is_even ? "Yes" : "No")
                << ", Desc: " << entry.description << std::endl;
        }
    }
}

const std::vector<NumberInfo>& Calculator::getHistory() const {
    return history;
}
