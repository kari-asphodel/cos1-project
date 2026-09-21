#pragma once
#include <string>
enum class Priority { Low = 1, Medium = 2,High = 3};
class Task
{
private:
	int id;
	std::string title;
	bool completed;
	Priority priority;
	std::string category;
public:
	Task(int taskId,std::string taskTitle, Priority taskPriority, std::string taskCategory, bool isCompleted = false);
	int GetId() const;
	std::string GetTitle() const;
	Priority GetPriority() const;
	std::string GetPriorityText() const;
	std::string GetCategory() const;
	bool IsCompleted() const;

	void CompleteTask();
};

