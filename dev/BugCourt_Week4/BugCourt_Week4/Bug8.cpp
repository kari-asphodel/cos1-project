#include <iostream>

void LevelUp(Player player)
{
    player.SetLevel(player.GetLevel() + 1);
}

void Bug8()
{
    Player hero;

    LevelUp(hero);

    std::cout << hero.GetLevel();
}