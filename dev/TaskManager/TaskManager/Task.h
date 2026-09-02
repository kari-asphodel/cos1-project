#pragma once
#include <string>
class Task
{
private:
	std::string title;
	bool completed;
public:
	Task(std::string taskTitle);

	std::string GetTitle() const;
	bool IsCompleted() const;

	void CompleteTask();
};

