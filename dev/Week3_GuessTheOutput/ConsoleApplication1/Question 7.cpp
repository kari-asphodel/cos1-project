#include <iostream>

class Potion
{
public:
    int strength;

    Potion(int value)
    {
        strength = value;
    }
};

int main()
{
    Potion potion;

    std::cout << potion.strength;

    return 0;
}

// A. 0
// B. Garbage value
// C. 1
// D. Does not compile - THIS ONE