#include "App.h"
#include <iostream>
#include <string>

App::App()
{
	isRunning = true;
}

void App::Run()
{
	std::cout << "Welcome to the Crypt Keeper Productivity Program.\n";
	std::cout << "Let us organize the chaos before it organizes us.";
	while (isRunning)
	{
		DisplayMenu();
		std::string input;
		std::getline(std::cin, input);
		int choice = std::stoi(input);

		HandleChoice(choice);
	}
}

void App::DisplayMenu() const
{
	std::cout << "\n==== CRYPT KEEPER ====\n";
	std::cout << "1. Add Task\n";
	std::cout << "2. View Tasks\n";
	std::cout << "3. Complete Task\n";
	std::cout << "4. Exit\n";
	std::cout << "Choose an option between 1 and 4: ";
}

void App::HandleChoice(int choice)
{
	std::string taskTitle; // for case 1
	switch (choice)
	{
	case 1:
		std::cout << "\nEnter a task title: ";
		std::getline(std::cin, taskTitle);
		manager.AddTask(title);
		break;
	case 2:
		manager.ViewTasks();
		break;
	case 3:
		std::cout << "\nComplete task is still sealed inside a future issue.\n";
		break;
	case 4:
		isRunning = false;
		std::cout << "\nThe crypt has been sealed. Goodbye.\n";
		break;
	default:
		std::cout << "\nThat option does not exist in this crpty.\n";
		break;
	}
}