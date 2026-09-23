#include <fstream>
void SavePlayer(std::string name, int level)
{
    std::ofstream file("player.txt");

    file << name << '\n';
    file << level << '\n';
}

void SaveScore(int score)
{
    std::ofstream file("player.txt");

    file << score << '\n';
}