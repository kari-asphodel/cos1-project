#include <iostream>
void AddTen(int number)
{
    number += 10;
}

void Output3()
{
    int value = 5;

    AddTen(value);

    std::cout << value;
}

//A 5
//B 10
//C 15
//D Compile Error
