#pragma once
#include "Task.h"
#include <string>
#include <vector>
class TaskManager
{
private:
	std::vector<Task> activeTasks;
	std::vector<Task> completedTasks;

	void DisplayTaskList(const std::vector<Task>& taskList, std::string heading) const;
public:
	void AddTask(std::string title, Priority priority, std::string category);

	void ViewActiveTasks() const;
	void ViewCompletedTasks() const;
	void ViewTasksByPriority(Priority priority) const;

	void CompleteTask(int index);
	void SortActiveTasksByPriority();


	void DisplaySummary() const;

	int GetActiveTaskCount() const;
};

