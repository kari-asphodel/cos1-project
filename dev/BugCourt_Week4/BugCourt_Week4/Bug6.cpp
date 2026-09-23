#include <iostream>

void Bug6()
{
    int choice;

    std::cout << "Enter a number: ";
    std::cin >> choice;

    while (choice < 1 || choice > 4)
    {
        std::cout << "Invalid choice. Try again: ";
        std::cin >> choice;
    }
}