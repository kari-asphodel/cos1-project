#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values = { 1, 2, 3 };

    for (int value : values)
    {
        value *= 2;
    }

    for (int value : values)
    {
        std::cout << value << " ";
    }

    return 0;
}

// A. 1 2 3 
// B. 2 4 6
// C. 2 2 2
// D. Does not compile