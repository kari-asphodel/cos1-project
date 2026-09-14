#include <iostream>

int main()
{
    int* number = new int(42);

    std::cout << *number << '\n';

    delete number;
    delete number;

    return 0;
}