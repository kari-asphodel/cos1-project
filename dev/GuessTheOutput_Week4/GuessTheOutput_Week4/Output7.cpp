#include <vector>
#include <iostream>

void Output7()
{
    std::vector<int> numbers = { 1, 2, 3 };

    for (int number : numbers)
    {
        number *= 2;
    }

    for (int number : numbers)
    {
        std::cout << number << " ";
    }
}

//A 1 2 3
//B 2 4 6
//C 2 2 2
//D Compile Error
