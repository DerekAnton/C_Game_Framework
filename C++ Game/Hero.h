#pragma once
#include "SDL.h"
#include "Image.h"
#include "Collision.h"
#include "AnimatedSprite.h"

class Hero: public AnimatedSprite
{
public:

	Hero();
	~Hero();

	void displayHero(SDL_Surface* screen);

	
private:

protected:

};
