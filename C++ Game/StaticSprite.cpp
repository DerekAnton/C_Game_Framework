#include "StaticSprite.h"

StaticSprite::StaticSprite(char* img_name)
{
	image = new Image(img_name);
	collision = new Collision(image);
}

StaticSprite::~StaticSprite()
{
	delete image;
	delete collision;
}