#include "TextData.h"

// there are 3 enemies, with 3 attacks each, with 5 responses per attack
Enemy trainingDummy;
Enemy finalBoss;
Enemy miniBoss;

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

	// set the enemies' health back to their default values
	trainingDummy.Reset();
	miniBoss.Reset();
	finalBoss.Reset();

	// training dummy
	trainingDummy.intro = R"(You yawn and squint your eyes at the sun. It's too early in the morning to start your life of adventuring. 
Your new adventuring master greets you. "Welcome to your first day as an adventurer!" She is way too energetic for sunrise. "First things first, you need some practice fighting. Here, take this." 
You get a sword.
"You're holding it wrong, here. Show me what you can do against that wooden training dummy.")";
	trainingDummy.success = R"(The training dummy falls apart at your feet. You raise your sword, triumphant! 

		Your adventuring master frowns. "Sheesh, well you didn't have to go and break the thing! Ugh, now I need to find a replacement." She throws up her hands and teleports away. )";
	trainingDummy.fail = R"(You drop your sword, exhausted. Your adventuring master finds you lying in a heap underneath the training dummy. So much for those 5 years you spent earning your Bachelor's of Adventuring. )";


	Attack training1("A slight breeze blows. The training dummy wobbles close towards you.");
	Response training1Slice(R"(
You try to slash at the training dummy, but it has wobbled too close and topples over on your shoulder.
You awkwardly sweep your sword across your stomach and use it to push the dummy off of your shoulder.)",
1, 1);
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
		{"slice", training1Stab},
		{"counter", training1Counter},
		{"dodge left", training1Dodge},
		{"dodge right", training1Dodge}
	};

	Attack training2(R"(The defenseless training dummy sways in the wind, staring cluelessly at you with its smiling face.
 Why does it have a smile, anyway?)");
	Response training2DodgeL(R"(You dodge to the left of the dummy. It has a smile painted on this side, too. )");
	Response training2DodgeR("You dodge to the right of the dummy. Now what?");
	Response training2Counter(R"(You ready yourself for a counterattack!
...
The dummy keeps smiling. Your adventuring master raises an eyebrow. 
)");
	Response training2Stab(R"(You just can't bring yourself to stab such a cute yet creepy face.
)");
	Response training2Slice(R"(You slice at the dummy's head, sending it spinning. All four of its faces smile at you in sequence until the head finally comes to a stop.)", 0, 1);

	training2.Responses =
	{
		{ "stab", training2Stab },
		{ "slice", training2Slice },
		{ "counter", training2Counter },
		{ "dodge left", training2DodgeL },
		{ "dodge right", training2DodgeR }
	};

	Attack training3("The wind changes direction and the training dummy begins to lean precariously to the left. ");

	Response training3DodgeL("You dodge spectacularly to the left, just as the training dummy falls and lands on top of you. You spend a few seconds propping it back up on its stand.", 2);
	Response training3DodgeR("You dodge away from the dummy as it collapses into the dirt to your left. Your adventuring master sighs and props it back up.");
	Response training3Counter("You hold your sword out to counter an attack from the left. The dummy falls onto your sword, and you stumble face first into the dirt from the sudden weight on your arms.", 1, 0);
	Response training3Stab("You take a stab, but the wind buffets the dummy aside before you connect. You manage to miss an inanimate object.");
	Response training3Slice("The dummy begins to tumble aside, but you slice across and nail the dummy in its wooden ribs.", 0, 1);

	training3.Responses =
	{
		{ "stab", training3Stab },
		{ "slice", training3Slice },
		{ "counter", training3Counter },
		{ "dodge left", training3DodgeL },
		{ "dodge right", training3DodgeR }
	};

	trainingDummy.Attacks = { training1, training2, training3 };

	// miniboss
	miniBoss.intro = "Suddenly the gentle breeze picks up. A great storm arrives in force, and a flood of water is quickly rushing past your feet. Just before you're swept away, you hop on board the torso of the dummy.\nYou're figting a flood.";
	miniBoss.success = "You ford the flood successfully. The waters die down and you find yourself standing on top of a wooden dummy inside a cave. You hop down to the stone floor. Hopefully nothing lives here.";
	miniBoss.fail = "You are too beaten up to carry on. Your loose your grasp on the training dummy's torso, and the last thing you see before the water sweeps you away are two of its smiles being washed away by the surging waters.";
	Attack mini1("As you navigate the waters you spy a large rock dead in your path. Poor rock.");
	Response mini1Stab("You stab the rock! The rock yells, \"Hey, watch it!\" and you sincerely apologize.");
	Response mini1Slice("You take a slash at the rock, and things go downhill from there. Your sword bounces off the hard surface and you nearly drop it in the water. As you fumble for your weapon you collide with the rock headfirst.");
	Response mini1Counter(R"(You brace yourself for the impact. As the rock approaches you reach with your hands and push off the rock, steering your ship safely around the obstacle. "Take that, flood!" You yell. The flood seems disappointed.)");
	Response mini1DodgeLeft("You roll the dummy's body to the left and plunge underwater. You collide with the rock, but the dummy's head takes most of the blow.");
	Response mini1DodgeRight("You roll the dummy's body to the right and plunge underwater. You collide with the rock, and take most of the blow to your head. At least you got around the rock");
	mini1.Responses =
	{
		{ "stab", mini1Stab },
		{ "slice",  mini1Slice },
		{ "counter", mini1Counter },
		{ "dodge left", mini1DodgeLeft },
		{ "dodge right", mini1DodgeRight }
	};

	Attack mini2("Flying fish assail you from the right!");
	Response mini2Counter(R"(You grab one of the fish out of the sky in passing and immediately eat it for dinner. Shocked, the other fish turn around midair and leave.)", -1, 1);
	Response mini2Stab("You skewer several fish on your sword and save them for sushi later.", -2, 1);
	Response mini2Slice("You make fillets.", 0, 1);
	Response mini2DodgeRight(R"(You dive directly into the cloud of fish shouting "Take me with you!" But the fish do not understand. Several of them smack you in the face.)", 2);
	Response mini2DodgeLeft("You duck away from the fish as they pass overhead.");
	mini2.Responses =
	{
		{ "stab", mini2Stab },
		{ "slice",  mini2Slice },
		{ "counter", mini2Counter },
		{ "dodge left", mini2DodgeLeft },
		{ "dodge right", mini2DodgeRight }
	};
	Attack mini3("A large wave begins to break, rolling from left to right just behind you.");
	Response mini3Stab("You stab the wave. The wave doesn't care. You're knocked over and you flounder in the surf until your hand slaps against the familiar wooden surface of the training dummy.", 1, 0);
	Response mini3Slice("You try to slice the wave in two. Did you really think that would work?", 1, 0);
	Response mini3Counter("You think fast and dive into the wave as it approaches. The waters rush over you but beneath the surface you remain unharmed.");
	Response mini3DodgeLeft("You ride the wave, dude. It's pretty cool, for the half second before the wave breaks and you tumble down. The flood is impressed.", 0, 1);
	Response mini3DodgeRight("Radical!", 0, 2);
	mini3.Responses =
	{
		{ "stab", mini3Stab },
		{ "slice",  mini3Slice },
		{ "counter", mini3Counter },
		{ "surf left", mini3DodgeLeft },
		{ "surf right", mini3DodgeRight }
	};
	miniBoss.Attacks = { mini1, mini2, mini3 };

	// final boss
	finalBoss.intro = "You are fighting the shadow beast.";
	finalBoss.fail = "The shadow beast devours you whole. Everything goes dark.";
	finalBoss.success = "Hey, you finished all the content I've written so far, so... you beat the game.";

	Attack final1("The beast gnashes its teeth and throws its head to the right.");
	Response final1DodgeRight("You leap towards the shadow beast’s snarling fangs just as it swings its head back. You collide with its snout, and one of its teeth bores into your side.", 2, 0);
	Response final1DodgeLeft("You dodge back to the left as the shadow beast lunges at the space where you stood a moment ago.");
	Response final1Counter("As the shadow beast swings its horrible maw towars you, you thrust your blade into its throat.", 0, 1);
	Response final1Stab("You try to stab the beast before it can attack, but the creature is too fast. Its fangs clamp down on your arm and you yelp in pain.", 3, 0);
	Response final1Slice("You slice to the side and connect with the beast's attack. You shear off some of its scales while your arms graze its razor sharp teeth.", 1, 1);

	final1.Responses =
	{
		{ "stab", final1Stab },
		{ "slice",  final1Slice },
		{ "counter", final1Counter },
		{ "dodge left", final1DodgeLeft },
		{ "dodge right", final1DodgeRight }
	};

	Attack final2("The shadow beast slaps its tail on the ground and begins thrashing it from right to left.");
	Response final2DodgeRight("You dodge to the right and avoid the tail as it swings around to your left");
	Response final2DodgeLeft("You dodge to the left but the tail suddenly comes full circle and knocks the wind out of you.",1);
	Response final2Counter("You catch the beast's tail as it swings, and then hold on for dear life as it flails you around against the cave floor.", 1);
	Response final2Slice("You try to slice the beast's throat, but get knocked aside by a swing of its tail.", 1);
	Response final2Stab("You step in close to the beast and stab it in the throat, just as its tail crashes down behind you.", 0, 1);

	final2.Responses =
	{
		{ "stab", final2Stab },
		{ "slice",  final2Slice },
		{ "counter", final2Counter },
		{ "dodge left", final2DodgeLeft },
		{ "dodge right", final2DodgeRight }
	};

	Attack final3("The beast rears up and begins charging its shadow laser attack!!");
	Response final3DodgeRight("You dodge aside and narrowly avoid being wiped from existence.");
	Response final3DodgeLeft("You dodge aside and glance back as the beam fries the ground where you stood.");
	Response final3Counter("You hold up your sword to reflect the beam back. The beast howls in pain!", 0, 2);
	Response final3Slice("You take a hefty slice at the beast's exposed belly, sending shadow scales skittering to the floor and interrupting its attack.", 0, 2);
	Response final3Stab("You step in to stab the beast in its belly. The beast buckles in pain and spatters some volatile shadow laser goo down your neck", 1, 1);

	final3.Responses =
	{
		{ "stab", final3Stab },
		{ "slice",  final3Slice },
		{ "counter", final3Counter },
		{ "dodge left", final3DodgeLeft },
		{ "dodge right", final3DodgeRight }
	};

	finalBoss.Attacks = { final1, final2, final3 };

}