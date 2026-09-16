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
	std::cout << "Today, the crypt learns to survive user chaos.";
	while (isRunning)
	{
		DisplayMenu();
		int choice = GetValidatedInputInRange(1, 8);
		HandleChoice(choice);
	}
}

void App::DisplayMenu() const
{
	std::cout << "\n==== CRYPT KEEPER ====\n";
	std::cout << "1. Add Task\n";
	std::cout << "2. View Active Tasks\n";
	std::cout << "3. Complete Task\n";
	std::cout << "4. View Completed Tasks\n";
	std::cout << "5. View Progress Summary\n";
	std::cout << "6. Sort by Priority\n";
	std::cout << "7. Filter by Priority\n";
	std::cout << "8. Exit\n";
	std::cout << "Choose an option between 1 and 8: ";
}

void App::HandleChoice(int choice)
{
	std::string taskTitle; // for case 1
	std::string category;//for case 1
	Priority priority; // for case 1
	Priority filterPriority; // for case 7

	int taskNumber; // for case 3
	switch (choice)
	{
	case 1:
		std::cout << "\nEnter a task title: ";
		std::getline(std::cin, taskTitle);
		priority = GetPriorityFromUser();
		std::cout << "Enter the task category, such as Rituals, Wards, Archives, or Crypt Care: ";
		std::getline(std::cin, category);
		manager.AddTask(taskTitle, priority, category);
		break;
	case 2:
		manager.ViewActiveTasks();
		break;
	case 3:
		if (manager.GetActiveTaskCount() == 0)
		{
			std::cout << "\nThere are no active tasks to complete.\n";
			return;
		}
		manager.ViewActiveTasks();
		std::cout << "\nEnter the task number to complete: ";
		taskNumber = GetValidatedInputInRange(1, manager.GetActiveTaskCount());
		manager.CompleteTask(taskNumber - 1);
		break;
	case 4:
		manager.ViewCompletedTasks();
		break;
	case 5:
		manager.DisplaySummary();
		break;
	case 6:
		manager.SortActiveTasksByPriority();
		break;
	case 7:
		std::cout << "\nChoose a priority to filter by.";
		filterPriority = GetPriorityFromUser();
		manager.ViewTasksByPriority(filterPriority);
		break;
	case 8:
		isRunning = false;
		std::cout << "\nThe crypt has been sealed. Goodbye.\n";
		break;
	default:
		std::cout << "\nThat option does not exist in this crypt.\n";
		break;
	}
}

int App::GetValidatedInputInRange(int min, int max)
{
	std::string input;
	int number;

	while (true)
	{
		std::getline(std::cin, input);
		try // try the risky code
		{
			number = std::stoi(input);
			if (number >= min && number <= max)
			{
				return number;
			}
			std::cout << "Invalid option. Please enter a number between " << min << " and " << max << ": ";
		}
		catch (...) //... is a catch all
		{
			std::cout << "Invalid option. Please enter a number between " << min << " and " << max << ": ";
		}
	}
}

Priority App::GetPriorityFromUser() 
{
	std::cout << "\nChoose task priority:\n";
	std::cout << "1. Low\n";
	std::cout << "2. Medium\n";
	std::cout << "3. High\n";
	std::cout << "Choose an option between 1 and 3: ";
	int choice = GetValidatedInputInRange(1, 3);
	if (choice == 1)
	{
		return Priority::Low;
	}
	else if (choice == 2)
	{
		return Priority::Medium;
	}
	return Priority::High;
}