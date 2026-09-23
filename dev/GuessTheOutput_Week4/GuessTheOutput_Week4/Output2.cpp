#include <iostream>
class Ghost
{
public:
    Ghost()
    {
        energy = 10;                                                              
    }

    void Haunt()
    {
        energy -= 3;
    }

    int GetEnergy()
    {
        return energy;
    }

private:
    int energy;
};

void Output2()
{
    Ghost ghost;

    ghost.Haunt();
    ghost.Haunt();

    std::cout << ghost.GetEnergy();
}

//A 10
//B 7
//C 4
//D 3