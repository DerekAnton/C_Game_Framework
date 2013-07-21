#pragma once
#include "StaticSprite.h"


class StaticSpriteDirector
{

public:
	static const int MAX_STATIC_SPRITES = 100;
	StaticSprite* static_array[StaticSpriteDirector::MAX_STATIC_SPRITES];

	enum Current_Static_Sprite { BACKGROUND, GROUND, WALL };
	Current_Static_Sprite current_sprite;


	StaticSpriteDirector();
	~StaticSpriteDirector();


private:

protected:

};