#include "Calculator.hpp"
#include <iostream>

int main() {
    Calculator calc;
    bool running = true;

    while (running) {
        std::cout << "\n--- Calculator Menu ---\n";
        std::cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n";
        std::cout << "Select an option: ";
        int choice;
        std::cin >> choice;

        if (choice >= 1 && choice <= 4) {
            double a, b;
            std::cout << "Enter first number: ";
            std::cin >> a;
            std::cout << "Enter second number: ";
            std::cin >> b;

            try {
                Operation op = static_cast<Operation>(choice - 1);
                double result = calc.compute(a, b, op);
                std::cout << "Result: " << result << "\n";
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        } else if (choice == 5) {
            calc.printHistory();
            running = false;
        } else {
            std::cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
