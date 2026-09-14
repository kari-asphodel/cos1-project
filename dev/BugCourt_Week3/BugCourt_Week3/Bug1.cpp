#include <iostream>
#include <string>

class Player
{
public:
    std::string name;

    void DisplayName()
    {
        std::cout << name << '\n';
    }
};

int main()
{
    Player player;
    player.name = "Asphodel";

    player.displayName();

    return 0;
}