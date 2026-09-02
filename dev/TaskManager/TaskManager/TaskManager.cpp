#include "TaskManager.h"
#include <iostream>

void TaskManager::AddTask(std::string title)
{
	tasks.push_back(Task(title));

	std::cout << "\nTask added to the crypt successfully.\n";
}

void TaskManager::ViewTasks() const
{
	std::cout << "\n==== TASK CRYPT ====\n";

	if (tasks.empty())
	{
		std::cout << "\nThe crypt is empty. No tasks haunt you... yet.\n";
		return;
	}

	for (int i = 0; i < tasks.size(); i++)
	{
		std::cout << i + 1 << ". "
				  << tasks[i].GetTitle()
				  << "\n";
	}
}