#pragma once
#include "Hero.h"
#include "AnimatedSprite.h"
#include "AnimatedSpriteDirector.h"
#include "StaticSpriteDirector.h"
#include "SDL.h"


class SpriteDirector
{

public:
	AnimatedSpriteDirector* ani_sprite_dir;
	StaticSpriteDirector* static_sprite_dir;

	SDL_Surface* screen;

	SpriteDirector();
	~SpriteDirector();

	int collisionLogic(AnimatedSprite* ani_sprite);

	Hero* getHero();

	void displayAll();

	bool moveAll();


private:

protected:

};
