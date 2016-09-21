#include "TextData.h"

Enemy TextData::trainingDummy;
Enemy TextData::finalBoss;
Enemy TextData::miniBoss;

Enemy* TextData::GetFirstEnemy()
{
	Init();
	return &trainingDummy;
}

void TextData::Init()
{
	// set up the order of enemies
	trainingDummy.successEnemy = &miniBoss;
	miniBoss.successEnemy = &finalBoss;
	
	Attack training1;
	training1.Text = "A slight breeze blows. The training dummy wobbles close towards you.";
	Response training1Slice( R"(
You try to slash at the training dummy, but it has wobbled too close and topples over on your shoulder.
You awkwardly sweep your sword across your stomach and use it to push the dummy off of your shoulder.)",
						1,1);
	Response training1Stab(R"(
The wind blows stronger. As the training dummy begins to fall towards you, you drive your sword into its wooden chest. 
The dummy's body splinters as it reels back. You get a splinter.
		)", 1, 2);
	Response training1Dodge("You dive and roll deftly to the side. The training dummy falls over on its own.");
	Response training1Counter(R"(You brace your blade across your chest, practicing your block.
A gust surges from behind the dummy and throws it into your blade, knocking you off balance. 
Surprised, you throw your weight behind your sowrd and knock the dummy back with a hefty shove.)", 0, 1);
	training1.Responses = 
	{
		{"stab", training1Slice},
		{"slash", training1Stab},
		{"counter", training1Counter},
		{"dodge left", training1Dodge},
		{"dodge right", training1Dodge}
	};

	trainingDummy.Attacks = { training1 };
}