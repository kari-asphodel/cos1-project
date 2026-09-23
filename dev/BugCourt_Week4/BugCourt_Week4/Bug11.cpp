#include <fstream>
#include <iostream>

void Bug11()
{
	std::ifstream file("save.txt");
	if (file.is_open())
	{


		std::string playerName;
		int level;

		file >> playerName;
		file >> level;

		std::cout << playerName << " Level " << level;
	}
	else
	{
		std::cout << "No save file found.\n";
	}
}