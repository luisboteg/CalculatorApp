#include "Calculator.hpp"
#include <iostream>
#include <cmath>
#include <sstream>

Calculator::Calculator() : current_order(1) {}

double Calculator::compute(double a, double b, Operation op) {
    double result;
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
            if (b == 0.0) throw std::invalid_argument("Division by zero");
            result = a / b;
            desc << a << " / " << b << " = " << result;
            break;
    }

    addToHistory(a, "Operand A");
    addToHistory(b, "Operand B");
    addToHistory(result, desc.str());

    return result;
}

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
    std::cout << "\n--- Operation History ---\n";
    for (const auto& entry : history) {
        std::cout << "Order: " << entry.order
                  << ", Value: " << entry.value
                  << ", Even: " << (entry.is_even ? "Yes" : "No")
                  << ", Desc: " << entry.description << "\n";
    }
}

const std::vector<NumberInfo>& Calculator::getHistory() const {
    return history;
}
