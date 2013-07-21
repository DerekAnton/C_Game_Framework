#include "AnimatedSpriteDirector.h"
#include "Hero.h"


AnimatedSpriteDirector::AnimatedSpriteDirector() // needs to be filled with animated sprite sprites.
{
	for(int counter = 0; counter < MAX_ANI_SPRITES; counter++)
	{
		animated_array[counter] = NULL;
	}
	animated_array[HERO] = (AnimatedSprite*) (new Hero());
}
AnimatedSpriteDirector::~AnimatedSpriteDirector()
{
	for(int counter = 0; counter < MAX_ANI_SPRITES; counter++)
	{
		if(animated_array[counter] != NULL)
		{
			delete animated_array[counter];
			animated_array[counter] = NULL;
		}
	}
}