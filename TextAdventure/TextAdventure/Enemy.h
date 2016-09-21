#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Attack.h"
#include "Response.h"
class Player;

class Enemy
{
public:
	int Health = 3;
	std::vector<Attack> Attacks;
	Enemy* failEnemy;
	Enemy* successEnemy;

	// do an attack and handle the response
	// return the next enemy, or null if there is none
	Enemy* RunChallenge(Player& p);

	void Print(Player p, Attack currentAttack);

	Enemy() = default;
	Enemy( Enemy* successE, std::vector<Attack> attacks, Enemy*failE, int health = 3);
private:
	Attack pickAttack();
	void handleResponse(Player &p, Response response);
};