#include <fstream>
#include <iostream>

//Assume numbers.txt contains :
//5
//10
//15


void Output8()
{
	std::ifstream file("numbers.txt");

	int number;
	int total = 0;

	while (file >> number)
	{
		total += number;
	}

	std::cout << total;
}

//A 5
//B 15
//C 30
//D Compile Error
