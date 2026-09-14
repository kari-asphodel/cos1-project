#include <iostream>

int main()
{
    int number = 10;

    int* first = &number;
    int* second = first;

    *second = 99;

    std::cout << *first;

    return 0;
}

// A. 10
// B. 99 - THIS ONE
// C. The address of number
// D. Does not compile