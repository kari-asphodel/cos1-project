#include "Task.h"
#include <utility>

Task::Task(int taskId, std::string taskTitle, Priority taskPriority, std::string taskCategory, bool isCompleted) : id(taskId), title(std::move(taskTitle)), priority(taskPriorty), category(std::move(taskCategory)), completed(isCompleted){ }

std::string Task::GetTitle() const
{
	return title;
}

int Task::GetId() const
{
	return id;
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