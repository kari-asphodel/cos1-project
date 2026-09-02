#pragma once
#include "Task.h"
#include <string>
#include <vector>
class TaskManager
{
private:
	std::vector<Task> tasks;
public:
	void AddTask(std::string title);
	void ViewTasks() const;
};

