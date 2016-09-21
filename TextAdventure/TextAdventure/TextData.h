#pragma once
#include "Enemy.h"

class TextData
{
public:
	static Enemy* GetFirstEnemy();
private:
	static void Init();
	static Enemy finalBoss;
	static Enemy miniBoss;
	static Enemy trainingDummy;
};