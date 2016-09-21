#include "Enemy.h"
#include "Attack.h"
#include <random>
#include "IO.h"
#include "Player.h"
#include "Response.h"

Enemy* Enemy::RunChallenge(Player& p) 
{
	while (Health > 0)
	{
		// print an attack
		Attack currentAttack = pickAttack();
		Print(p, currentAttack);
		IO::Print("Enter command: ");

		// get input
		bool responseValid = false;
		std::string action;
		while (responseValid == false)
		{
			action = IO::ReadLn();
			if (!currentAttack.HasResponseFor(action))
			{
				Print(p, currentAttack);
				IO::PrintLn(action + ": Command not recognized.");
				IO::Print("Enter command: ");
			}
			else
			{
				responseValid = true;
			}
		}

		// handle response
		Response response = currentAttack.GetResponse(action);
		handleResponse(p, response);
		// fight again?
		if (p.Health <= 0)
		{
			// player died :(
			return failEnemy;
		}
	}
	// player won!
	return successEnemy;
}

Attack Enemy::pickAttack() 
{
	if (Attacks.size() == 0)
	{
		return Attack();
	}
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, Attacks.size() - 1);
	return Attacks[distribution(generator)];
}

void Enemy::handleResponse(Player& p, Response response)
{
	p.Health -= response.PlayerDamage;
	Health -= response.EnemyDamage;
	response.Print();
	IO::EnterToContinue();
}

Enemy::Enemy(Enemy* successE, std::vector<Attack> attacks, Enemy*failE, int health)
{
	successEnemy = successE;
	Attacks = attacks;
	failEnemy = failE;
	Health = health;
}

void Enemy::Print(Player p, Attack currentAttack)
{
	IO::ClearScreen();

	IO::Print("Player health: ");
	IO::Print(std::to_string(p.Health));
	IO::Print("\tEnemy health: ");
	IO::Print(std::to_string(Health));
	IO::PrintLn();

	currentAttack.Print();
}