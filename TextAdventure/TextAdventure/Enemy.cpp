#include "Enemy.h"
#include <assert.h>
#include <random>

#include "Attack.h"
#include "IO.h"
#include "Player.h"
#include "Response.h"

// fight runs the combat loop until the player or the enemy is defeated
// the combat loop is a turned based fight where the player chooses an action in response to what the enemy is doing
Enemy* Enemy::Fight(Player& p) 
{
	IO::PrintSimplePrompt(intro);
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
			IO::PrintSimplePrompt(fail);
			return failEnemy;
		}
	}
	// player won!
	IO::PrintSimplePrompt(success);
	return successEnemy;
}

// choose an attack randomly
std::default_random_engine generator;
Attack Enemy::pickAttack() 
{
	assert( Attacks.size() > 0);
	std::uniform_int_distribution<int> distribution(0, Attacks.size() - 1);
	return Attacks[distribution(generator)];
}

// print the response and deal damage
void Enemy::handleResponse(Player& p, Response response)
{
	p.Health -= response.PlayerDamage;
	Health -= response.EnemyDamage;
	response.Print();
	IO::EnterToContinue();
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