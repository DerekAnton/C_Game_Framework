#include "SpriteDirector.h"
#include "AnimatedSpriteDirector.h"
#include "Hero.h"
#include "Collision.h"
#include "AnimatedSprite.h"

SpriteDirector::SpriteDirector()
{
	ani_sprite_dir = new AnimatedSpriteDirector();
	static_sprite_dir = new StaticSpriteDirector();
}
SpriteDirector::~SpriteDirector()
{
	delete ani_sprite_dir;
	delete static_sprite_dir;

}

bool SpriteDirector::moveAll()
{ 
	bool to_draw = false;

	for(int counter = 0; counter < AnimatedSpriteDirector::MAX_ANI_SPRITES; counter++)
	{
		if(ani_sprite_dir->animated_array[counter] == NULL)
			break;

		ani_sprite_dir->animated_array[counter]->last_collision =  collisionLogic(ani_sprite_dir->animated_array[counter]);


		if(ani_sprite_dir->animated_array[counter]->move())
			to_draw = true;
	}

	return to_draw;
}

void SpriteDirector::displayAll()
{
	for(int counter = 0; counter < AnimatedSpriteDirector::MAX_ANI_SPRITES; counter++)
	{
		if(ani_sprite_dir->animated_array[counter] == NULL)
			break;
		if(counter  == AnimatedSpriteDirector::HERO)
			((Hero*) ani_sprite_dir->animated_array[counter])->displayHero(screen);

	}
}

Hero* SpriteDirector::getHero()
{
	return  ((Hero*) ani_sprite_dir->animated_array[AnimatedSpriteDirector::HERO]);
}

int SpriteDirector::collisionLogic(AnimatedSprite* ani_sprite)
{

	// EVENETUALLY , WE WILL CHECK ANIMATED SPRITES AGAINST THE ANIMATED SPRITE, BUT FOR NOW ONLY STATIC SPRITES ARE NEEDED.
	for(int counter = 0; counter < StaticSpriteDirector::MAX_STATIC_SPRITES; counter ++)
	{
		int holder = ani_sprite->collision->checkCollision(static_sprite_dir->static_array[counter]->collision);
		
		if(holder != Collision::NO_HIT)
			return holder;
	}

	return Collision::NO_HIT;
}
