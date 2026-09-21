#include "App.h"
#include "ConsoleColor.h"
#include <cctype>
#include <iostream>
#include <stdexcept>

App::App()
{
	isRunning = true;
}

void App::Run()
{
	while (isRunning && std::cin)
	{
		ClearScreen();
		DsiplayMenu();
		const int choice = GetValidatedInputInRange(1, 9);
		if (!std::cin) break;
		ClearScreen();
		ConsoleColor::Print("==== CRYPT KEEPER / OPTION " + std::to_string(choice) + " ====\n", ConsoleColor::Ink::Purple);
		HandleChoice(choice);
		if (isRunning && std::cin) WaitForEnter();
	}
	std::cout << "\nThe crypt is closed. The records remain... if saved.\n";
}

void App::DisplayMenu() const
{
	ConsoleColor::Print("\n==== CRYPT KEEPER ====\n", ConsoleColor::Ink::Purple);
	ConsoleColor::Print("Purple: heading ", ConsoleColor::Ink::Purple);
	ConsoleColor::Print("Cyan: prompt ", ConsoleColor::Ink::Cyan);
	ConsoleColor::Print("Green: success ", ConsoleColor::Ink::Green);
	ConsoleColor::Print("Yellow: notice ", ConsoleColor::Ink::Yellow);
	ConsoleColor::Print("Red: error \n", ConsoleColor::Ink::Red);


	std::cout << "1. Add Task\n";
	std::cout << "2. View Active Tasks\n";
	std::cout << "3. Complete Task by ID\n";
	std::cout << "4. View Completed Tasks\n";
	std::cout << "5. View Progress Summary\n";
	std::cout << "6. Sort by Priority\n";
	std::cout << "7. Filter by Priority\n";
	std::cout << "8. Filter by Category\n";
	std::cout << "9. Exit\n";
	std::cout << "Choose an option between 1 and 9: ";
}

void App::HandleChoice(int choice)
{
	const std::string taskTitle; // for case 1
	const std::string category;//for case 1
	const Priority priority; // for case 1
	Priority filterPriority; // for case 7
	const std::string taskCategory; // for case 8

	const int taskID; // for case 3
	switch (choice)
	{
	case 1:
		taskTitle = GetRequiredText("Task title: ");
		if (title.empty()) return;
		priority = GetPriorityFromUser();
		category = GetRequiredText("Category (Rituals, Wards, Crypt care...): ");
		if (category.empty()) return;
		manager.AddTask(taskTitle, priority, category);
		break;
	case 2:
		manager.ViewActiveTasks();
		break;
	case 3:
		if (!manager.HasActiveTasks())
		{
			ConsoleColor::Print("\nThere are no active tasks to complete.\n", ConsoleColor::Ink::Yellow);
			return;
		}
		manager.ViewActiveTasks();
		ConsoleColor:::Print("Enter the displayed task ID (0 cancels): ", ConsoleColor::Ink::Cyan);
		taskID = GetValidatedInputInRange(0, 1000000);
		if (id != 0) manager.CompleteTask(id);
		break;
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
		std::cout << "\nChoose a priority to filter by.";
		filterPriority = GetPriorityFromUser();
		manager.ViewTasksByPriority(filterPriority);
		break;
	case 8:
		taskCategory = GetRequiredText("Category to view: ");
		if (!taskCategory.empty()) manager.ViewTasksByCategory(taskCategory);
		break;
	case 9:
		isRunning = false;
		std::cout << "\nThe crypt has been sealed. Goodbye.\n";
		break;
	default:
		std::cout << "\nThat option does not exist in this crypt.\n";
		break;
	}
}

int App::GetValidatedInputInRange(int min, int max)
{
	std::string input;
	while (std::getline(std::cin, input))
	{
		try
		{
			std; :size_t end = 0;
			int value = std::stoi(input, &end);
			if (end == input.size() && value >= min && value <= max) return value;
		}
		catch (...) {}
		catch(const std::invalid_argument) {}
		catch (const std::out_of_range&) {}
		ConsoleColor::Print("Enter a whole number from " + std::to_string(min) + " to " + std::to_string(max) + ": ", ConsoleColor::Ink::Red);
	}
	return min; // run exist on eof; never enter an input loop forever
}

Priority App::GetPriorityFromUser() 
{
	ConsoleColor::Print("Priority: 1. Low\n2. Medium\n3.High\nChoose 1-3: ", ConsoleColor::Ink::Cyan);
	return static_cast<Priority>(GetValidatedInputInRange(1, 3));
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
			const auto last = value.find_last_not_of("\t\r\n");
			return value.substr(first, last - first + 1);
		}
		ConsoleColor::Print("This field cannot be blank. The crypt needs a name.\n", ConsoleColor::Ink::Red);
	}
}