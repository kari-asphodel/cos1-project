#include <iostream>

void Bug6()
{
    int choice;
    std::string input;
    std::cout << "Enter a number: ";
    std::getline(std::cin, input);
    try
    {
        choice = std::stoi(input);
    }
    catch (...)
    {
        std::cout << "Please enter a number.\n";
    }

    while (choice < 1 || choice > 4)
    {
        std::cout << "Invalid choice. Try again: ";
        std::cin >> choice;
    }
}