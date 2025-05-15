#include "Calculator.hpp"
#include <iostream>

/**
 * @brief Displays the main calculator menu
 */
void printMainMenu() 
{
    std::cout << R"(
--- Calculator Menu ---
1. Add
2. Subtract
3. Multiply
4. Divide
5. Print History
6. Save to File
7. Load from File
8. Filter Data
9. Exit
Select an option: )";
}

/**
 * @brief Displays the filter menu and applies the selected filter to the calculator history
 * @param calc Reference to the Calculator instance
 */
void showFilterMenu(Calculator& calc) 
{
    std::cout<<"--- Filter Menu--- \n";
    std::cout << "1. Show even numbers\n";
    std::cout << "2. Show odd numbers\n";
    std::cout << "3. Show additions only\n";
    std::cout << "4. Show subtractions only\n";
    std::cout << "5. Show multiplications only\n";
    std::cout << "6. Show divisions only\n";
    std::cout << "Select filter: ";

    int filter_choice;
    std::cin >> filter_choice;

    switch (filter_choice) 
    {
    case 1:
        calc.filterAndPrint(true, false);
        break;
    case 2:
        calc.filterAndPrint(false, true);
        break;
    case 3: 
    {
        Operation op = Operation::ADDITION;
        calc.filterAndPrint(true, true, &op);
        break;
    }
    case 4: 
    {
        Operation op = Operation::SUBTRACTION;
        calc.filterAndPrint(true, true, &op);
        break;
    }
    case 5: 
    {
        Operation op = Operation::MULTIPLICATION;
        calc.filterAndPrint(true, true, &op);
        break;
    }
    case 6: 
    {
        Operation op = Operation::DIVISION;
        calc.filterAndPrint(true, true, &op);
        break;
    }
    default:
        std::cout << "Invalid filter option." << std::endl;
    }
}

/**
 * @brief Main application entry point. Provides a text menu to perform calculator operations and manage history.
 */
int main() 
{
    Calculator calc;
    bool running = true;

    while (running) 
    {
        printMainMenu();
        int choice;
        std::cin >> choice;

        double a, b;

        switch (choice) 
        {
        case 1:
        case 2:
        case 3:
        case 4: // Handle arithmetic operations
            std::cout << "Enter first number: ";
            std::cin >> a;
            std::cout << "Enter second number: ";
            std::cin >> b;
            try 
            {
                Operation op = static_cast<Operation>(choice - 1);
                double result = calc.compute(a, b, op); // TODO replace with muParser
                std::cout << "Result: " << result << std::endl;
            }
            catch (const std::exception& e) 
            {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        case 5:
            calc.printHistory();
            break;

        case 6:
            calc.saveToFile("history.txt");
            std::cout << "History saved." << std::endl;
            break;

        case 7:
            calc.loadFromFile("history.txt");
            std::cout << "History loaded." << std::endl;
            break;

        case 8:
            showFilterMenu(calc);
            break;

        case 9:
            running = false;
            break;
        default:
            std::cout << "Invalid option. Try again." << std::endl;
            break;
        }

        // Clear input state in case of invalid entries
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
