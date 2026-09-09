#include <iostream>
#include <vector>
void Case1()
{
    int health = 100;

    if (health == 0)
    {
        std::cout << "You have died.\n";
    }
}
void Case2()
{
    while (true)
    {
        std::cout << "1. Exit\n";

        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            std::cout << "Goodbye!\n";
            break;
        }
    }
}
void Case3()
{
    std::vector<int> scores = { 10, 20, 30 };

    for (int i = 0; i < scores.size(); i++)
    {
        std::cout << scores[i] << "\n";
    }
}
void Case4()
{
    int gold = 5635;

    std::cout << gold << "\n";

}
void Case5()
{
    std::vector<std::string> inventory;

    inventory.push_back("Sword");

    inventory.clear();

    if (!inventory.empty())
    {
        std::cout << inventory[0];
    }
}
void Case6()
{
    int health = 50;

    while (health < 100)
    {
        std::cout << "Healing...\n";
        health += 10;
    }
}
void Case7()
{
    int dragons = 5;

    dragons -= 10;
    if (dragons < 0)
    {
        dragons = 0;
    }
    std::cout << dragons;
}
void Case8()
{
    std::cout << "1. Play\n";
    std::cout << "2. Exit\n";
    std::cout << "7. Secret Shop\n";

    if (choice == 7)
    {
        openSecretShop();
    }
}
void Case9()
{
    Potion* potion = new Potion();

    potion->drink();
    delete potion;
    potion = nullptr;
}
void Case10()
{
    try {
        std::string input;
        std::getline(std::cin, input);
        int choice = std::stoi(input);
    }
    catch (...)
    {
        std::cout << "Invalid choice";
    }
    std::cout << "You chose: " << choice;
}
int main()
{
    Case1();
    //Case2();
    //Case3();
    //Case4();
    //Case5();
    //Case6();
    //Case7();
    //Case8();
    //Case9();
    //Case10();
}