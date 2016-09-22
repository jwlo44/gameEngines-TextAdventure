#pragma once
#include <string>
// a response is the damage result of a player's choice during an attack
class Response
{
public:
	std::string Text;
	// the damage dealt to the player
	int PlayerDamage = 0;
	// the damage dealt to the enemy
	int EnemyDamage = 0;

	// print the flavor text and damage text
	void Print();

	Response() = default;
	Response(std::string Text, int playerDamage = 0, int enemyDamage = 0);
};
