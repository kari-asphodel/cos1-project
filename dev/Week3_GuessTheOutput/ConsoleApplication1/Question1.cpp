#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers = { 2, 4, 6 };

    numbers.push_back(8);

    std::cout << numbers.size() << '\n';
    std::cout << numbers[2];

    return 0;
}

// A. 3 6
// B. 4 6 - THIS ONE
// C. 4 8
// D. Does not compile
