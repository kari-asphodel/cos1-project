#include <iostream>
#include <string>

class Character
{
private:
    std::string name;
    int health;

public:
    Character(std::string n, int h)
    {
        name = n;
        health = h;
    }

    Character(const Character& other)
    {
        name = other.name;
        health = other.health;
    }

    void Display()
    {
        std::cout << name << ": " << health << '\n';
    }
};

int main()
{
    Character player1("Morrigan", 100);
    Character player2 = player1;

    player2.Display();

    return 0;
}