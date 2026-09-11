#pragma once
#include "TaskManager.h"
class App
{
private:
	TaskManager manager;
	bool isRunning;

	void DisplayMenu() const;
	int GetValidatedInputInRange(int min, int max);
	void HandleChoice(int choice);
public:
	App();

	void Run();
};

