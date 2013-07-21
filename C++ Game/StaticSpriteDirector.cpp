#include "StaticSpriteDirector.h"

StaticSpriteDirector::StaticSpriteDirector()
{

	for(int counter = 0; counter < MAX_STATIC_SPRITES; counter++)
	{
		static_array[counter] = NULL;
	}

	static_array[BACKGROUND] = new StaticSprite("starting.png");
	static_array[GROUND] = new StaticSprite("Full_Ground.png");
	static_array[WALL] = new StaticSprite("Wall.png");

}
StaticSpriteDirector::~StaticSpriteDirector()
{

	for(int counter = 0; counter <  MAX_STATIC_SPRITES; counter++)
	{
		if(static_array[counter] != NULL)
			delete static_array[counter];
		else
			break;
	}

}