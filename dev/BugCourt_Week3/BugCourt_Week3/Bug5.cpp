#include <iostream>

int* CreateScore()
{
    int score = 100;

    return &score;
}

int main()
{
    int* scorePtr = CreateScore();

    std::cout << *scorePtr << '\n';

    return 0;
}