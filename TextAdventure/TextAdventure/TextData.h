#pragma once
#include "Enemy.h"

// TextData contains and sets up all the text content for the game
class TextData
{
public:
	// GetFirstEnemy returns the pointer to the first enemy in the game
	// call this at the beginning of the main loop
	static Enemy* GetFirstEnemy();
private:
	// init is called each time the game begins
	// init sets up all the static text data and state transitions for the game
	static void Init();
	// TextData is a static class
	TextData() = delete;
};