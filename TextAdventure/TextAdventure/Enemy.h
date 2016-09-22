#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Attack.h"
#include "Response.h"
class Player;
// an enemy is a state in the game that holds a unique set of attack states
class Enemy
{
public:
	int Health = 3;
	std::vector<Attack> Attacks;
	Enemy* failEnemy;
	Enemy* successEnemy;
	std::string intro;
	std::string success;
	std::string fail;

	// do an attack and handle the response
	// return the next enemy, or null if there is none
	Enemy* Fight(Player& p);

	// reset this enemy's health back to its default value
	void Reset() { Health = 3; }
	void Print(Player p, Attack currentAttack);
private:
	Attack pickAttack();
	void handleResponse(Player &p, Response response);
};