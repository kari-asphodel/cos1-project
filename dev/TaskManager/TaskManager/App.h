#pragma once
#include "TaskManager.h"
#include <string>
class App
{
private:
	TaskManager manager;
	bool isRunning = true;
	void ClearScreen() const;
	void WaitForEnter() const;
	void DisplayMenu() const;
	int GetValidatedInputInRange(int min, int max) const;
	std::string GetRequiredText(const std::string& prompt) const;
	void HandleChoice(int choice);
	Priority GetPriorityFromUser();

public:
	App();

	void Run();
};

