#include <iostream>

int CalculateDamage(int attack, int defense)
{
    int damage = attack - defense;
}

int main()
{
    int damage = CalculateDamage(20, 5);

    std::cout << damage;

    return 0;
}