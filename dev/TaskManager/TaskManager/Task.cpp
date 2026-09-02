#include "Task.h"

Task::Task(std::string taskTitle)
{
	title = taskTitle;
	completed = false;
}

std::string Task::GetTitle() const
{
	return title;
}

bool Task::IsCompleted() const
{
	return completed;
}

void Task::CompleteTask()
{
	completed = true;
}