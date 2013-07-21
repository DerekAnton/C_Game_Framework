#pragma once
#include "AnimatedSprite.h"

class AnimatedSpriteDirector
{

public:
	static const int MAX_ANI_SPRITES = 100;
	
	enum Current_Ani_Sprite { HERO, ENEMY };
	Current_Ani_Sprite current_sprite;

	AnimatedSprite* animated_array[MAX_ANI_SPRITES];
	//AnimatedSprite* hero;

	AnimatedSpriteDirector();
	~AnimatedSpriteDirector();

private:

protected:

};