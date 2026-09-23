#include <vector>
#include <iostream>

void Bug10()
{
    std::vector<std::string> enemies;
    if (!enemies.empty())
    {
        std::cout << "First enemy: "
            << enemies[0]
            << '\n';
    }
    else
    {
        std::cout << "There are no enemies.\n";
    }
}