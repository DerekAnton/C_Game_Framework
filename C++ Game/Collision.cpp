#include "Collision.h"
#include "SDL.h"
#include "Image.h"

Collision::Collision(Image* img)
{
	hitbox = img->clip[0];
}

Collision::~Collision()
{

}

int Collision::checkCollision(Collision* other_object)
{
	int right_side = this->hitbox.x + this->hitbox.w;
	int bottom_side = this->hitbox.y + this->hitbox.h;

	int other_bottom = other_object->hitbox.y + other_object->hitbox.h;

	if(bottom_side >= other_object->hitbox.y)
		return VERT_HIT;
	if(other_bottom >= this->hitbox.y)
		return VERT_HIT;

	return NO_HIT;
}