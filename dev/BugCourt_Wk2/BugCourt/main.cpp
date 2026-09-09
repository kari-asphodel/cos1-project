#include <iostream>
#include <vector>
void Case1()
{
    int health = 100;

    if (health = 0)
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
        }
    }
}
void Case3()
{
    std::vector<int> scores = { 10, 20, 30 };

    for (int i = 0; i <= scores.size(); i++)
    {
        std::cout << scores[i] << "\n";
    }
}
void Case4()
{
    int gold;

    std::cout << gold << "\n";

}
void Case5()
{
    std::vector<std::string> inventory;

    inventory.push_back("Sword");

    inventory.clear();

    std::cout << inventory[0];
}
void Case6()
{
    int health = 50;

    while (health < 100)
    {
        std::cout << "Healing...\n";
    }
}
void Case7()
{
    int dragons = 5;

    dragons -= 10;

    std::cout << dragons;
}
void Case8()
{
    std::cout << "1. Play\n";
    std::cout << "2. Exit\n";

    if (choice == 7)
    {
        openSecretShop();
    }
}
void Case9()
{
    Potion* potion = new Potion();

    potion->drink();
}
void Case10()
{
    int choice;

    std::cin >> choice;

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