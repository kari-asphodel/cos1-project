#pragma once
#include "Task.h"
#include <string>
#include <vector>
class TaskManager
{
private:
	std::vector<Task> activeTasks;
	std::vector<Task> completedTasks;
public:
	void AddTask(std::string title);

	void ViewActiveTasks() const;
	void ViewCompletedTasks() const;

	void CompleteTask(int index);

	int GetActiveTaskCount() const;
};

