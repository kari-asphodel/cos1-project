#include <iostream>
#include <string>

class Enemy
{
public:
    std::string name;
    int health;
};

int main()
{
    Enemy monster;

    monster.name = "Grave Crawler";
    monster.health = 100;

    std::cout << monster.health;

    return 0;
}