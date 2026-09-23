#include <iostream>
#include <vector>

void Bug2()
{
    std::vector<std::string> monsters =
    {
        "Goblin",
        "Skeleton",
        "Vampire"
    };

    for (int i = 0; i < monsters.size(); i++)
    {
        std::cout << monsters[i] << '\n';
    }
}