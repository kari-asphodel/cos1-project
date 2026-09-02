#pragma once
#include "TaskManager.h"
class App
{
private:
	TaskManager manager;
	bool isRunning;

	void DisplayMenu() const;
	void HandleChoice(int choice);
public:
	App();

	void Run();
};

