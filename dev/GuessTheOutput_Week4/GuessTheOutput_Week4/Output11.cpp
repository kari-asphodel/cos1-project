#include <iostream>
class Weapon
{
public:
    Weapon(int damage)
    {
        this->damage = damage;
    }

    int GetDamage()
    {
        return damage;
    }

private:
    int damage;
};

class Player
{
public:
    Player()
    {
        health = 20;
    }

    void TakeDamage(Weapon weapon)
    {
        health -= weapon.GetDamage();
    }

    int GetHealth()
    {
        return health;
    }

private:
    int health;
};

void Output11()
{
    Weapon sword(6);
    Player player;

    player.TakeDamage(sword);
    player.TakeDamage(sword);

    std::cout << player.GetHealth();
}


//A 6
//B 8
//C 14
//D 20
