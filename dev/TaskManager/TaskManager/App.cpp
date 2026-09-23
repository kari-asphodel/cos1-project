#include "App.h"
#include "ConsoleColor.h"
#include <cctype>
#include <iostream>
#include <stdexcept>

App::App()
{
    isRunning = true;
}

void App::ClearScreen() const
{
#ifdef _WIN32
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info{};
    if (output != INVALID_HANDLE_VALUE && GetConsoleScreenBufferInfo(output, &info))
    {
        const DWORD cells = static_cast<DWORD>(info.dwSize.X) * info.dwSize.Y;
        const COORD home{ 0, 0 };
        DWORD written = 0;
        FillConsoleOutputCharacterA(output, ' ', cells, home, &written);
        FillConsoleOutputAttribute(output, info.wAttributes, cells, home, &written);
        SetConsoleCursorPosition(output, home);
        return;
    }
#endif
    // Other terminals scroll the old view away without shell commands.
    std::cout << std::string(35, '\n');
}

void App::WaitForEnter() const
{
    ConsoleColor::Print("\nPress Enter to return to the crypt menu...", ConsoleColor::Ink::Cyan);
    std::string unused;
    std::getline(std::cin, unused);
}

void App::DisplayMenu() const
{
    ConsoleColor::Print("========== CRYPT KEEPER ==========\n", ConsoleColor::Ink::Purple);
    ConsoleColor::Print("Purple: heading  ", ConsoleColor::Ink::Purple);
    ConsoleColor::Print("Cyan: prompt  ", ConsoleColor::Ink::Cyan);
    ConsoleColor::Print("Green: success  ", ConsoleColor::Ink::Green);
    ConsoleColor::Print("Yellow: notice  ", ConsoleColor::Ink::Yellow);
    ConsoleColor::Print("Red: error\n", ConsoleColor::Ink::Red);
    std::cout << "1. Add Task\n2. View Active Tasks\n3. Complete Task by ID\n"
        << "4. View Completed Tasks\n5. View Progress Summary\n"
        << "6. Sort Active Tasks by Priority\n7. Filter by Priority\n"
        << "8. Filter by Category\n9. Save Text Ledger\n10.Load Text Ledger\n11.Save Binary Ledger\n12.Load Binary Ledger\n13.Quit\nChoose 1-13: ";
}

int App::GetValidatedInputInRange(int min, int max) const
{
    std::string input;
    while (std::getline(std::cin, input))
    {
        try
        {
            std::size_t end = 0;
            int value = std::stoi(input, &end);
            if (end == input.size() && value >= min && value <= max)
                return value;
        }
        catch (const std::invalid_argument&) {}
        catch (const std::out_of_range&) {}
        ConsoleColor::Print("Enter a whole number from " + std::to_string(min) +
            " to " + std::to_string(max) + ": ", ConsoleColor::Ink::Red);
    }
    return min; // Run exits on EOF; never enter an input loop forever.
}

std::string App::GetRequiredText(const std::string& prompt) const
{
    std::string value;
    while (true)
    {
        ConsoleColor::Print(prompt, ConsoleColor::Ink::Cyan);
        if (!std::getline(std::cin, value)) return "";
        const auto first = value.find_first_not_of(" \t\r\n");
        if (first != std::string::npos)
        {
            const auto last = value.find_last_not_of(" \t\r\n");
            return value.substr(first, last - first + 1);
        }
        ConsoleColor::Print("This field cannot be blank. The crypt needs a name.\n", ConsoleColor::Ink::Red);
    }
}

Priority App::GetPriorityFromUser()
{
    ConsoleColor::Print("Priority: 1. Low  2. Medium  3. High\nChoose 1-3: ", ConsoleColor::Ink::Cyan);
    return static_cast<Priority>(GetValidatedInputInRange(1, 3));
}

void App::HandleChoice(int choice)
{
    switch (choice)
    {
    case 1:
    {
        const std::string taskTitle = GetRequiredText("Task title: ");
        if (taskTitle.empty()) return;
        const Priority priority = GetPriorityFromUser();
        const std::string category = GetRequiredText("Category (Rituals, Wards, Crypt Care...): ");
        if (category.empty()) return;
        manager.AddTask(taskTitle, priority, category);
        break;
    }
    case 2:
        manager.ViewActiveTasks();
        break;
    case 3:
    {
        if (!manager.HasActiveTasks())
        {
            ConsoleColor::Print("No active tasks to complete.\n", ConsoleColor::Ink::Yellow);
            return;
        }
        manager.ViewActiveTasks();
        ConsoleColor::Print("Enter the displayed task ID (0 cancels): ", ConsoleColor::Ink::Cyan);
        const int taskID = GetValidatedInputInRange(0, 1000000);
        if (taskID != 0) manager.CompleteTask(taskID);
        break;
    }
    case 4:
        manager.ViewCompletedTasks();
        break;
    case 5:
        manager.DisplaySummary();
        break;
    case 6:
        manager.SortActiveTasksByPriority();
        break;
    case 7:
    {
        const Priority filterPriority = GetPriorityFromUser();
        manager.ViewTasksByPriority(filterPriority);
        break;
    }
    case 8:
    {
        const std::string taskCategory = GetRequiredText("Category to view: ");
        if (!taskCategory.empty()) manager.ViewTasksByCategory(taskCategory);
        break;
    }
    case 9:
        manager.SaveToTextFile("tasks.txt");
        break;
    case 10:
        manager.LoadFromTextFile("tasks.txt");
        break;
    case 11:
        manager.SaveToBinaryFile("tasks.dat");
        break;
    case 12:
        manager.LoadFromBinaryFile("tasks.dat");
        break;
    case 13:
        isRunning = false;
        break;
    default:
        ConsoleColor::Print("That option does not exist in this crypt.\n", ConsoleColor::Ink::Red);
        break;
    }
}

void App::Run()
{
    while (isRunning && std::cin)
    {
        ClearScreen();
        DisplayMenu();
        const int choice = GetValidatedInputInRange(1, 13);
        if (!std::cin) break;
        ClearScreen();
        ConsoleColor::Print("=== CRYPT KEEPER / OPTION " + std::to_string(choice) + " ===\n", ConsoleColor::Ink::Purple);
        HandleChoice(choice);
        if (isRunning && std::cin) WaitForEnter();
    }
    std::cout << "\nThe crypt is closed. The records remain... if saved.\n";
}