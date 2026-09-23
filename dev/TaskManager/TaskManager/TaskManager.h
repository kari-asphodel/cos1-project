#pragma once
#include "Task.h"
#include <string>
#include <vector>
class TaskManager
{
private:
	std::vector<Task> activeTasks;
	std::vector<Task> completedTasks;
	int nextId = 1;

	void DisplayTaskList(const std::vector<Task>& taskList, std::string& heading) const;
public:
	void AddTask(const std::string& title, Priority priority, const std::string& category);

	void ViewActiveTasks() const;
	void ViewCompletedTasks() const;
	void ViewTasksByPriority(Priority priority) const;
	void ViewTasksByCategory(const std::string& category) const;

	void CompleteTask(int id);
	void SortActiveTasksByPriority();


	void DisplaySummary() const;

	int GetActiveTaskCount() const;
	bool HasActiveTasks() const;

	bool SaveToTextFile(const std::string& fileName)const;
	bool LoadFromTextFile(const std::string& fileName);

	bool SaveToBinaryFile(const std::string& fileName) const;
	bool LoadFromBinaryFile(const std::string& fileName);

};

