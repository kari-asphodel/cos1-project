#include <iostream>

class Vampire
{
private:
    int age;

public:
    Vampire()
    {
        age = 400;
    }
};

int main()
{
    Vampire dracula;

    std::cout << dracula.age;

    return 0;
}

// A. 400
// B. 0
// C. Garbage value
// D. Does not compile  - THIS ONE