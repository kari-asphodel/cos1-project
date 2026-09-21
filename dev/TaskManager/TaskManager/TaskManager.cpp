#include "TaskManager.h"
#include "ConsoleColor.h"
#include <algorithm>
#include <cctype>
#include <iostream>

namespace
{
    std::string Lower(std::string text)
    {
        for (char& ch : text)
            ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
        return text;
    }
}

void TaskManager::AddTask(const std::string& title, Priority priority,
    const std::string& category)
{
    activeTasks.emplace_back(nextId++, title, priority, category);
    ConsoleColor::Print("Task added to the crypt.\n", ConsoleColor::Ink::Green);
}

void TaskManager::DisplayTaskList(const std::vector<Task>& tasks,
    std::string& heading) const
{
    ConsoleColor::Print("\n=== " + heading + " ===\n", ConsoleColor::Ink::Purple);
    if (tasks.empty())
    {
        ConsoleColor::Print("No tasks found. The crypt is quiet... suspiciously quiet.\n", ConsoleColor::Ink::Yellow);
        return;
    }
    for (const Task& task : tasks)
        std::cout << "ID " << task.GetId() << ". " << task.GetTitle()
        << " | Priority: " << task.GetPriorityText()
        << " | Category: " << task.GetCategory() << '\n';
}

void TaskManager::ViewActiveTasks() const
{
    std::string heading = "ACTIVE TASKS";
    DisplayTaskList(activeTasks, heading);
}

void TaskManager::ViewCompletedTasks() const
{
    std::string heading = "COMPLETED TASKS";
    DisplayTaskList(completedTasks, heading);
}

void TaskManager::ViewTasksByPriority(Priority priority) const
{
    std::vector<Task> matches;
    for (const Task& task : activeTasks)
        if (task.GetPriority() == priority) matches.push_back(task);
    const std::string label = priority == Priority::High ? "HIGH" :
        priority == Priority::Medium ? "MEDIUM" : "LOW";
    std::string heading = label + " PRIORITY TASKS";
    DisplayTaskList(matches, heading);
}

void TaskManager::ViewTasksByCategory(const std::string& category) const
{
    std::vector<Task> matches;
    for (const Task& task : activeTasks)
        if (Lower(task.GetCategory()) == Lower(category)) matches.push_back(task);
    std::string heading = "CATEGORY: " + category;
    DisplayTaskList(matches, heading);
}

void TaskManager::SortActiveTasksByPriority()
{
    std::stable_sort(activeTasks.begin(), activeTasks.end(),
        [](const Task& a, const Task& b)
        {
            return static_cast<int>(a.GetPriority()) >
                static_cast<int>(b.GetPriority());
        });
    ConsoleColor::Print("The loudest demons rise first.\n", ConsoleColor::Ink::Yellow);
}

void TaskManager::CompleteTask(int id)
{
    auto found = std::find_if(activeTasks.begin(), activeTasks.end(),
        [id](const Task& task) { return task.GetId() == id; });
    if (found == activeTasks.end())
    {
        ConsoleColor::Print("No active task has that ID.\n", ConsoleColor::Ink::Red);
        return;
    }
    found->CompleteTask();
    completedTasks.push_back(*found);
    activeTasks.erase(found);
    ConsoleColor::Print("Task completed and moved to the completed crypt.\n", ConsoleColor::Ink::Green);
}

void TaskManager::DisplaySummary() const
{
    ConsoleColor::Print("\n=== CRYPT SUMMARY ===\n", ConsoleColor::Ink::Purple);
    std::cout << "Active Tasks: " << activeTasks.size()
        << "\nCompleted Tasks: " << completedTasks.size()
        << "\nTotal Tasks Created: " << activeTasks.size() + completedTasks.size()
        << '\n';
}

bool TaskManager::HasActiveTasks() const { return !activeTasks.empty(); }

int TaskManager::GetActiveTaskCount() const
{
    return static_cast<int>(activeTasks.size());
}