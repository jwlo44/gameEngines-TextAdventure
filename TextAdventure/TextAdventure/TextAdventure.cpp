#include "IO.h"
#include "Player.h"
#include "Enemy.h"
#include "TextData.h"
int main()
{
	bool playAgain = true;
	while (playAgain)
	{	
		Player p;
		Enemy* e = TextData::GetFirstEnemy();
		while (e != nullptr)
		{
			e = e->Fight(p);
		}
		playAgain = IO::PlayAgain();
	}
    return 0;
}

