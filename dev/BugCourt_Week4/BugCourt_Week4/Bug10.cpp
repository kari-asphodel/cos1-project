#include <vector>
#include <iostream>

void Bug10()
{
    std::vector<std::string> enemies;

    std::cout << "First enemy: "
        << enemies[0]
        << '\n';
}