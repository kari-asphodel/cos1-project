#include <iostream>

int main()
{
    int choice = 0;

    while (choice != 3)
    {
        std::cout << "1. Play\n";
        std::cout << "2. Instructions\n";
        std::cout << "3. Exit\n";
        std::cout << "Choice: ";

        std::cin >> choice;

        if (choice == 1)
        {
            std::cout << "Playing...\n";
        }
        else if (choice == 2)
        {
            std::cout << "Instructions...\n";
        }
    }

    return 0;
}