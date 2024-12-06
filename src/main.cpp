#include <iostream>
#include <stdexcept>
#include "calculator.h"

void printMenu() {
    std::cout << "Select an operation:" << std::endl;
    std::cout << "1. Add" << std::endl;
    std::cout << "2. Subtract" << std::endl;
    std::cout << "3. Multiply" << std::endl;
    std::cout << "4. Divide" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

int main() {
    while (true) {
        printMenu();

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Exiting the calculator. Goodbye!" << std::endl;
            break;
        }

        double num1, num2;
        std::cout << "Enter the first number: ";
        std::cin >> num1;
        std::cout << "Enter the second number: ";
        std::cin >> num2;

        try {
            switch (choice) {
                case 1:
                    std::cout << "Result: " << add(num1, num2) << std::endl;
                break;
                case 2:
                    std::cout << "Result: " << subtract(num1, num2) << std::endl;
                break;
                case 3:
                    std::cout << "Result: " << multiply(num1, num2) << std::endl;
                break;
                case 4:
                    std::cout << "Result: " << divide(num1, num2) << std::endl;
                break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
