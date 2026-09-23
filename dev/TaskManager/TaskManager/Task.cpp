#include "Task.h"
#include <utility>

Task::Task(int taskId, std::string taskTitle, Priority taskPriority,
    std::string taskCategory, bool isCompleted)
    : id(taskId), title(std::move(taskTitle)), priority(taskPriority),
    category(std::move(taskCategory)), completed(isCompleted) {}

int Task::GetId() const { return id; }
std::string Task::GetTitle() const { return title; }
Priority Task::GetPriority() const { return priority; }
std::string Task::GetCategory() const { return category; }
bool Task::IsCompleted() const { return completed; }
void Task::CompleteTask() { completed = true; }

std::string Task::GetPriorityText() const
{
    if (priority == Priority::High) return "High";
    if (priority == Priority::Medium) return "Medium";
    return "Low";
}