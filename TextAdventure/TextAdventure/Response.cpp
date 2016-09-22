#include "Response.h"
#include "IO.h"

void Response::Print()
{
	IO::ClearScreen();
	IO::PrintLn(Text);
	if (PlayerDamage > 0)
	{
		IO::PrintLn("You took " + std::to_string(PlayerDamage) + " damage! Ouch!");
	}
	if (PlayerDamage < 0)
	{
		IO::PrintLn("You healed " + std::to_string(PlayerDamage) + " damage. Stayin' alive!");
	}
	if (EnemyDamage > 0)
	{
		IO::PrintLn("You dealt " + std::to_string(EnemyDamage) + " damage!");
	}
	IO::PrintLn();
}

Response::Response(std::string text, int playerDamage, int enemyDamage)
{
	Text = text;
	PlayerDamage = playerDamage;
	EnemyDamage = enemyDamage;
}