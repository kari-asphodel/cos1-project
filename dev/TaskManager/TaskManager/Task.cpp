#include "Task.h"

Task::Task(std::string taskTitle, Priority taskPriority, std::string taskCategory)
{
	title = taskTitle;
	completed = false;
	priority = taskPriority;
	category = taskCategory;
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

Priority Task::GetPriority() const
{
	return priority;
}

std::string Task::GetCategory() const
{
	return category;
}

std::string Task::GetPriorityText() const
{
	if (priority == Priority::High)
	{
		return "High";
	}
	else if (priority == Priority::Medium)
	{
		return "Medium";
	}
		return "Low";
	
}