#pragma once
#include <iostream>
#include <string>
#ifdef _WIN32
#define NOMINMAX
#include "Windows.h"
#endif

namespace ConsoleColor
{
	enum class Ink {Purple, Cyan, Green, Yellow, Red};
	inline void Print(const std::string& message, Ink ink)
	{
#ifdef _WIN32
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO original{};
		if (output != INVALID_HANDLE_VALUE && GetConsoleScreenBufferInfo(output, &original))
		{
            WORD color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
            if (ink == Ink::Cyan)
                color = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
            else if (ink == Ink::Green)
                color = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
            else if (ink == Ink::Yellow)
                color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
            else if (ink == Ink::Red)
                color = FOREGROUND_RED | FOREGROUND_INTENSITY;

            std::cout.flush();
            SetConsoleTextAttribute(output,
                (original.wAttributes & 0xFFF0) | color);
            std::cout << message << std::flush;
            SetConsoleTextAttribute(output, original.wAttributes);
            return;
        }
#else
        (void)ink;
#endif
        std::cout << message;
		
	}
}