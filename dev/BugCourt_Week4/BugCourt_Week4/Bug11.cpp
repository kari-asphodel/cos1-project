#include <fstream>
#include <iostream>

void Bug11()
{
	std::ifstream file("save.txt");

	std::string playerName;
	int level;

	file >> playerName;
	file >> level;

	std::cout << playerName << " Level " << level;
}