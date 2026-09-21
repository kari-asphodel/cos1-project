#include "TaskManager.h"
#include "ConsoleColor.h"
#include <iostream>
#include <algorithm>
#include <cctype>
namespace
{
	std::string Lower(std::strig text)
	{
		for (char& ch : text)
		
			ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));

		return text;
	}
}

void TaskManager::AddTask(const std::string& title, Priority priority, const std::string& category)
{
	activeTasks.emplace_back(nextId++, title, priority, category);
	ConsoleColor::Print("\nTask added to the crypt successfully.\n", ConsoleColor::Ink::Green);
}

void TaskManager::ViewActiveTasks() const
{
	DisplayTaskList(activeTasks, "ACTIVE TASKS");
}

void TaskManager::ViewCompletedTasks() const
{
	DisplayTaskList(completedTasks, "COMPLETED TASKS");
}

void TaskManager::CompleteTask(int index)
{
	auto found = std::find_if(activeTasks.begin(), activeTasks.end(),
		[id](const Task& task) { return task.GetId() == id; });
	if (found == activeTasks.end())
	{
		ConsoleColor::Print("No active task has that ID.\n", ConsoleColor::Ink::Red);
		return;
	}
	found->CompleteTask();
	completedTasks.push_back(*found);
	activeTasks.erase(found);
	ConsoleColor::Print("Task completed and moved to the completed crypt.\n", ConsoleColor::Ink::Green);
}

int TaskManager::GetActiveTaskCount() const
{
	return activeTasks.size();
}

void TaskManager::DisplaySummary() const
{
	ConsoleColor::Print("\n==== CRYPT SUMMARY ====\n", ConsoleColor::Ink::Purple);
	std::cout << "Active Tasks: " << activeTasks.size() << "\n";
	std::cout << "Completed Tasks: " << completedTasks.size() << "\n";
	std::cout << "Total Tasks Created: " << activeTasks.size()+completedTasks.size() << "\n";
}

void TaskManager::DisplayTaskList(const std::vector<Task>& taskList, std::string& heading)const
{
	ConsoleColor::Print("\n==== " + heading + " ====\n", ConsoleColor::Ink::Purple);

	if (taskList.empty())
	{
		ConsoleColor::Print("\nNo tasks found. The crypt is quiet.\n", ConsoleColor::Ink::Yellow);
		return;
	}

	for (const Task& task : taskList)
	{
		std::cout << "ID " << task.GetId() << ". " << task.GetTitle()
			<< " | Priority: " << task.GetPriorityText()
			<< " | Category: " << task.GetCategory() << "\n";

	}
}

void TaskManager::SortActiveTasksByPriority()
{
	std::stable_sort(
		activeTasks.begin(),
		activeTasks.end(),
		[](const Task& first, const Task& second)
		{
			return static_cast<int>(first.GetPriority()) > 
				static_cast<int>(second.GetPriority());
		}
	);
	ConsoleColor::Print("The loudest demons rise first.\n", ConsoleColor::Ink::Yellow);
}

void TaskManager::ViewTasksByPriority(Priority priority) const
{
	std::vector<Task> filterTasks;
	for (const Task& task : activeTasks)
	{
		if (task.GetPriority() == priority) filterTasks.push_back(task);
	}

	const std::string heading;
	if (priority == Priority::High)
	{
		heading = "HIGH PRIORITY TASKS";
	}
	else if (priority == Priority::Medium)
	{
		heading = "MEDIUM PRIORITY TASKS";
	}
	else
	{
		heading = "LOW PRIORITY TASKS";
	}
	DisplayTaskList(filterTasks, heading);
}

void TaskManager::ViewTasksByCategory(const std::string& category) const
{
	std::vector<Task> matches;
	for (const Task& task : activeTasks)
		if (Lower(task.GetCategory()) == Lower(category)) matches.push_back(task);
	DisplayTaskList(matches, "CATEGORY: " + category);
}

bool TaskManager::HasActiveTasks() const { return !activeTasks.empty(); }