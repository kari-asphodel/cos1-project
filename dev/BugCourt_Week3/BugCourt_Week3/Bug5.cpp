#include <iostream>

int CreateScore()
{
    return 100;
}

int main()
{
    int score = CreateScore();

    std::cout << score << '\n';

    return 0;
}