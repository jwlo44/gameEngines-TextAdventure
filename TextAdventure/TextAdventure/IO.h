#pragma once
#include <string>

class IO
{
public:
	static void ClearScreen();
	static void Print(std::string str);
	static void PrintLn(std::string str);
	static void PrintLn(int numLines = 1);
	static std::string ReadLn();
	static bool PlayAgain();
	static void EnterToContinue();
private:
	IO() = delete;
};
