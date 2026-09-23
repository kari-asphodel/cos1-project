#include <iostream>
#include <vector>

void Output1()
{
    std::vector<int> numbers = { 2, 4, 6 };

    for (int number : numbers)
    {
        std::cout << number + 1 << " ";
    }
}

/*
A 2 4 6
B 3 5 7
C 1 3 5
D Compile Error
*/