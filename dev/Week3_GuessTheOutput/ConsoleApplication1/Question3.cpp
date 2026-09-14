#include <iostream>

int main()
{
    int score = 25;
    int* ptr = &score;

    *ptr = 50;

    std::cout << score;

    return 0;
}

// A. 25
// B. 50  - THIS ONE
// C. Memory Address
// D. Does not compile