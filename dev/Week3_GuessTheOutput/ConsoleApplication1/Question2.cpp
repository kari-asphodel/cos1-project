#include <iostream>

class Ghost
{
public:
    void Haunt()
    {
        std::cout << "Boo!";
    }
};

int main()
{
    Ghost ghost;

    ghost.haunt();

    return 0;
}

// A. Boo!
// B. Haunt
// C. Nothing
// D. Does not compile 