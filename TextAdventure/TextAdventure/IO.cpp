#include "IO.h"
#include <iostream>

void IO::ClearScreen()
{
	PrintLn(30);
}

void IO::PrintSimplePrompt(std::string str)
{
	ClearScreen();
	PrintLn(str);
	EnterToContinue();
}

void IO::Print(std::string str)
{
	std::cout << str;
}

void IO::PrintLn(std::string str)
{
	Print(str);
	PrintLn();
}

void IO::PrintLn(int numlines)
{
	for (int i = 0; i < numlines; ++i)
	{
		std::cout << "\n";
	}
}

std::string IO::ReadLn()
{
	std::string line;
	std::getline(std::cin, line);
	return line;
}

bool IO::PlayAgain()
{
	PrintLn("Play again? y/n");
	std::string yn = ReadLn();
	if (yn == "y") { return true; }
	if (yn == "n") { return false; } 
    PrintLn("Type y or n.");
	return PlayAgain();
}

void IO::EnterToContinue()
{
	PrintLn("Press enter to continue.");
	ReadLn();
}