#include <iostream>

void Round1()
{
    int total = 0;

    for (int i = 1; i <= 3; i++)
    {
        total += i;
    }

    std::cout << total;
    // A. 3
    // B. 6
    // C. 9
    // D. The Loop Has Betrayed Us
}
void Round2()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << i << " ";
    }
    // A. 0 1 2
    // B. 1 2 3
    // C. 0 1 2 3
    // D. Infinite void
}
void Round3()
{
    int health = 0;

    if (health == 0)
    {
        std::cout << "Dead";
    }
    else
    {
        std::cout << "Alive";
    }
    // A. Dead
    // B. Alive
    // C. Nothing
    // D. Health files a complaint
}
void Round4()
{
    std::vector<std::string> items = { "Sword", "Shield", "Potion" };

    std::cout << items[1];
    // A. Sword
    // B. Shield
    // C. Potion
    // D. The vector screams
}
void Round5()
{
    bool hasKey = false;

    if (!hasKey)
    {
        std::cout << "Door locked";
    }
    else
    {
        std::cout << "Door opens";
    }
    // A. Door locked
    // B. Door opens
    // C. false
    // D. The key was never real
}
int Round6DoubleNumber(int number)
{
    return number * 2;
}
void Round6()
{
    std::cout << Round6DoubleNumber(4);
    // A. 4
    // B. 6
    // C. 8
    // D. The function refuses
}
void Round7()
{
    std::string name = "Goblin";

    std::cout << "Hello, " << name;
    // A. Hello
    // B. Goblin
    // C. Hello, Goblin
    // D. Hello, name
}
void Round8()
{
    int potions = 2;

    potions--;

    std::cout << potions;
    // A. 1
    // B. 2
    // C. 3
    // D. Potion evaporates
}
void Round9()
{
    int choice = 2;

    if (choice == 1)
    {
        std::cout << "Add";
    }
    else if (choice == 2)
    {
        std::cout << "View";
    }
    else
    {
        std::cout << "Exit";
    }
    // A. Add
    // B. View
    // C. Exit
    // D. All of them
}
void Round10()
{
    std::vector<int> numbers = { 4, 8, 15, 16 };

    std::cout << numbers.size();
    // A. 3
    // B. 4
    // C. 16
    // D. Lost numbers detected
}
void BonusRound()
{
    std::vector<std::string> items = { "Sword", "Shield", "Potion" };

    std::cout << items[3];
    // A. Sword
    // B. Shield
    // C. Potion
    // D. Out-of-bounds problem
}
int main()
{
    Round1();
    //Round2();
    //Round3();
    //Round4();
    //Round5();
    //Round6();
    //Round7();
    //Round8();
    //Round9();
    //Round10();
    //BonusRound();
}