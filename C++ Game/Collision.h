#pragma once
#include "SDL.h"
#include "Image.h"

class Collision
{
public:
	enum CollisionEnum {COLLIDABLE, DAMAGE}; // include this .h file within the class that is creating the objects that will be deemed immovable or dmgable by referencing it as Collision::CollisionEnum::X <- whatever the thing needs to be
	CollisionEnum collision_state;

	enum CollisionType{ NO_HIT, VERT_HIT, HORZ_HIT};
	CollisionType collision_type;

	SDL_Rect hitbox;
	bool colliding;

	Collision(Image* img);
	~Collision();

	int checkCollision(Collision* other_object);

private:

protected:

};