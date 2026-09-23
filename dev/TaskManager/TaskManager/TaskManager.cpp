#include "TaskManager.h"
#include "ConsoleColor.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <set>
#include <cstring>
#include <cstdint>


namespace
{
    std::string Lower(std::string text)
    {
        for (char& ch : text)
            ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
        return text;
    }
    bool WriteNumber(std::ofstream& file, std::uint32_t value)
    {
        file.write(reinterpret_cast<const char*>(&value), sizeof(value));
        return static_cast<bool>(file);
    }
    bool ReadNumber(std::ifstream& file, std::uint32_t& value)
    {
        file.read(reinterpret_cast<char*>(&value), sizeof(value));
        return static_cast<bool>(file);
    }
    bool WriteString(std::ofstream& file, const std::string& text)
    {
        if (text.size() > 1000 || !WriteNumber(file, static_cast<std::uint32_t>(text.size())))
            return false;
        file.write(text.data(), static_cast<std::streamsize>(text.size()));
        return static_cast<bool>(file);
    }
    bool ReadString(std::ifstream& file, std::string& text)
    {
        std::uint32_t length = 0;
        if (!ReadNumber(file, length) || length > 1000) return false;
        text.resize(length);
        file.read(text.data(), static_cast<std::streamsize>(length));
        return static_cast<bool>(file);
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

bool TaskManager::SaveToTextFile(const std::string& fileName)const
{
    std::ofstream file(fileName, std::ios::trunc);
    if (!file) {
        ConsoleColor::Print("Could not open the text ledger for saving\n", ConsoleColor::Ink::Red);
        return false;
    }
    file << "CRYPT_TEXT_V1 " << activeTasks.size() << ' ' << completedTasks.size() << "\n";
    auto writeTask = [&file](const Task& task)
        {
            file << task.GetId() << ' ' << static_cast<int>(task.GetPriority()) << ' '
                << (task.IsCompleted() ? 1 : 0) << ' '
                << std::quoted(task.GetTitle()) << ' '
                << std::quoted(task.GetCategory()) << '\n';
        };
    for (const Task& task : activeTasks) writeTask(task);
    for (const Task& task : completedTasks) writeTask(task);
    file.close();
    if (!file)
    {
        ConsoleColor::Print("Text save did not finish. Check the file location.\n", ConsoleColor::Ink::Red);
        return false;
    }
    ConsoleColor::Print("The text ledger is sealed: " + fileName + "\n", ConsoleColor::Ink::Green);
    return true;
}

bool TaskManager::LoadFromTextFile(const std::string& fileName)
{
    std::ifstream file(fileName);
    if (!file)
    {
        ConsoleColor::Print("No text ledger found. Current tasks are safe.\n", ConsoleColor::Ink::Red);
        return false;
    }
    std::string header, headerLine;
    int activeCount = 0, completedCount = 0;
    if (!std::getline(file, headerLine))
    {
        ConsoleColor::Print("Invalid text ledger. Current tasks are safe.\n", ConsoleColor::Ink::Red);
        return false;
    }
    std::istringstream headerStream(headerLine);
    if (!(headerStream >> header >> activeCount >> completedCount) ||
        header != "CRYPT_TEXT_V1" || activeCount < 0 || completedCount < 0 ||
        activeCount > 10000 || completedCount > 10000)
    {
        ConsoleColor::Print("Invalid text ledger. Current tasks are safe.\n", ConsoleColor::Ink::Red);
        return false;
    }
    headerStream >> std::ws;
    if (!headerStream.eof())
    {
        ConsoleColor::Print("Invalid text ledger header. Current tasks are safe.\n", ConsoleColor::Ink::Red);
        return false;
    }
    std::vector<Task> newActive, newCompleted;
    std::set<int> ids;
    int highestId = 0;
    for (int i = 0; i < activeCount + completedCount; ++i)
    {
        std::string line, title, category;
        int id = 0, priority = 0, completed = -1;
        if (!std::getline(file, line))
        {
            ConsoleColor::Print("Incomplete text ledger. Current tasks are safe.\n", ConsoleColor::Ink::Red);
            return false;
        }
        std::istringstream row(line);
        if (!(row >> id >> priority >> completed >> std::quoted(title)
            >> std::quoted(category)) || id < 1 || id > 1000000 ||
            priority < 1 || priority > 3 || (completed != 0 && completed != 1) ||
            title.find_first_not_of(" \t") == std::string::npos ||
            category.find_first_not_of(" \t") == std::string::npos ||
            title.size() > 1000 || category.size() > 1000 ||
            !ids.insert(id).second || completed != (i >= activeCount ? 1 : 0))
        {
            ConsoleColor::Print("Invalid task in text ledger. Current tasks are safe.\n", ConsoleColor::Ink::Red);
            return false;
        }
        row >> std::ws;
        if (!row.eof())
        {
            ConsoleColor::Print("Extra data in text ledger. Current tasks are safe.\n", ConsoleColor::Ink::Red);
            return false;
        }
        Task task(id, title, static_cast<Priority>(priority), category, completed == 1);
        if (completed) newCompleted.push_back(task);
        else newActive.push_back(task);
        highestId = std::max(highestId, id);
    }
    file >> std::ws;
    if (!file.eof())
    {
        ConsoleColor::Print("Extra records in text ledger. Current tasks are safe.\n", ConsoleColor::Ink::Red);
        return false;
    }
    activeTasks = std::move(newActive);
    completedTasks = std::move(newCompleted);
    nextId = highestId + 1;
    ConsoleColor::Print("The text ledger has been restored.\n", ConsoleColor::Ink::Green);
    return true;
}

bool TaskManager::SaveToBinaryFile(const std::string& fileName) const
{
    std::ofstream file(fileName, std::ios::biinary | std::ios::trunc);
    if (!file)
    {
        ConsoleColor::Print("Could not open the binary ledger for saving.\n", ConsoleColor::Ink::Red);
        return false;
    }
    file.write("CKB1", 4);
    const bool validCounts = activeTasks.size() <= 10000 && completedTasks.size() <= 10000;
    bool ok = validCounts &&
        WriteNumber(file, static_cast<std::uint32_t>(activeTasks.size())) &&
        WriteNumber(file, static_cast<std::uint32_t>(completedTasks.size()));

    auto writeTask = [&file](const Task& task)
        {
            return WriteNumber(file, static_cast<std::uint32_t>(task.GetId())) && 
                   WriteNumber(file, static_cast<std::uint32_t>(task.GetPriority())) &&
                   WriteString(file, task.GetTitle()) && 
                   WriteString(file, task.GetCategory());
        };
    if (ok) for (const Task& task : activeTasks) if (!writeTask(task)) ok = false;
    if (ok) for (const Task& task : completedTasks) if (!writeTask(task)) ok = false;
    file.close();
    if (!ok || !file)
    {
        ConsoleColor::Print("Binary save did not finish.\n", ConsoleColor::Ink::Red);
        return false;
    }
    ConsoleColor::Print("The binary ledger is sealed: " + fileName + "\n", ConsoleColor::Ink::Green);
    return true;
}

bool TaskManager::LoadFromBinaryFile(const std::string& fileName)
{
    std::ifstream file(fileName, std::ios::binary);
    if (!file)
    {
        ConsoleColor::Print("No binary ledger found. Current tasks are safe.\n", ConsoleColor::Ink::Red);
        return false;
    }
    char magic[4]{};
    std::uint32_t activeCount = 0, completedCount = 0;
    if (!file.read(magic, 4) || std::memcmp(magic, "CKB1", 4) != 0 ||
        !ReadNumber(file, activeCount) || !ReadNumber(file, completedCount) ||
        activeCount > 10000 || completedCount > 10000)
    {
        ConsoleColor::Print("Invalid binary ledger. Current tasks are safe.\n", ConsoleColor::Ink::Red);
        return false;
    }
    std::vector<Task> newActive, newCompleted;
    std::set<int>ids;
    int highestId - 0;
    for (std::uint32_t i = 0; i < activeCount + completedCount; ++i)
    {
        std::uint32_t id = 0, priority = 0;
        std::string title, category;
        if (!ReadNumber(file, id) || !ReadNumber(file, priority) ||
            !ReadString(file, title) || !ReadString(file, category) ||
            id < 1 || id > 1000000 || priority < 1 || priority > 3 ||
            title.find_first_not_of(" \t") == std::string::npos ||
            category.find_first_not_of(" \t") == std::string::npos ||
            !ids.insert(static_cast<int>(id)).second)
        {
            ConsoleColor::Print("Damaged binary ledger. Current tasks are safe.\n", ConsoleColor::Ink::Red);
            return false;
        }

        const bool complete = i >= activeCount;
        Task task(static_cast<int>(id), title, static_cast<Priority>(priority), category, complete);
        if (complete) newCompleted.push_back(task);
        else newActive.push_back(task);
        highestId = std::max(highestId, static_cast<int>(id));
    }
    if (file.peek() != std::char_traits<char>::eof())
    {
        ConsoleColor::Print("Extra binary record. Current tasks are safe.\n", ConsoleColor::Ink::Red);
        return false;
    }
    activeTasks = std::move(newActive);
    completedTasks = std::move(newCompleted);
    nextId = highestId + 1;
    ConsoleColor::Print("The binary ledgerr has been restored.\n", ConsoleColor::Ink::Green);
    return true;
}