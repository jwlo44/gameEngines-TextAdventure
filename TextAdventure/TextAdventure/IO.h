#pragma once
#include <string>

// the IO class manages all prints to the console and some simple text prompts
class IO
{
public:
	static void ClearScreen();
	static void PrintSimplePrompt(std::string str);
	static void Print(std::string str);
	static void PrintLn(std::string str);
	static void PrintLn(int numLines = 1);
	static std::string ReadLn();
	static bool PlayAgain();
	static void EnterToContinue();
private:
	IO() = delete;
};
