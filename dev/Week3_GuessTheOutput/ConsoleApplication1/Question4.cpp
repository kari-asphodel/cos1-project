#include <iostream>

class Creature
{
public:
    int health;

    Creature(int h)
    {
        health = h;
    }
};

int main()
{
    Creature first(100);
    Creature second = first;

    second.health = 50;

    std::cout << first.health << " "
        << second.health;

    return 0;
}

// A. 100 50 
// B. 50 50
// C. 100 100
// D. Does not compile