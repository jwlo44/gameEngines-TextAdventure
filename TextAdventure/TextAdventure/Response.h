#pragma once
#include <string>
class Response
{
public:
	std::string Text;
	int PlayerDamage = 0;
	int EnemyDamage = 0;

	void Print();

	Response() = default;
	Response(std::string Text, int playerDamage = 0, int enemyDamage = 0);
};
