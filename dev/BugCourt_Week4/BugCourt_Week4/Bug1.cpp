#include <iostream>
int main()
{
    int choice = 0;

    while (choice != 4)
    {
        std::cout << "1. Add Item\n";
        std::cout << "2. View Items\n";
        std::cout << "3. Remove Item\n";
        std::cout << "4. Exit\n";

        std::cin >> choice;

        if (choice == 1)
        {
            std::cout << "Adding item...\n";
        }
        else if (choice == 2)
        {
            std::cout << "Viewing items...\n";
        }
        else if (choice == 3)
        {
            std::cout << "Removing item...\n";
        }
        else if (choice == 4)
        {
            choice = 0;
        }
    }
}
