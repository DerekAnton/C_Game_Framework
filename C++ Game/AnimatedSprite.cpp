
#include "AnimatedSprite.h"
#include "AnimatedSpriteDirector.h"



AnimatedSprite::AnimatedSprite()
{
	last_collision = 0; // THIS DENTOES THE NO_HIT FOR NOW...(enum)

	for(int counter = 0; counter < MAX_SPRITE_IMAGES; counter++)
	{
		sprite_list[counter] = NULL;
	}

}

AnimatedSprite::~AnimatedSprite()
{

}

void AnimatedSprite::init(int width, int height, int speed, int jump_vel)
{
	sprite_width = width; 
	sprite_height = height;
	this->speed = speed; 
	jump_velocity = jump_vel;
}





	
bool AnimatedSprite::move()
{
	bool time_to_draw = false;

	x_offset += x_distance;
	
	if(jumping)
		jump();

	if(last_collision == Collision::VERT_HIT)
		jumping = false;
		
	if(jumping && y_offset >= resting_y)
		jumping = false;
		

	if( (x_offset < 0) || ( x_offset + speed > (640 - sprite_width) ) )
	{
		x_offset -= x_distance;
	}
	
	if(displayedImage->sprite_frame_limiter == -1) 
		return true;

	if(frameLimiter > displayedImage->sprite_frame_limiter)
	{
		currentFrame++;
		frameLimiter = -1;
		time_to_draw = true;
	}
	else
	{
		frameLimiter++;
	}
	return time_to_draw;
}

void AnimatedSprite::jump()
{
	double distance = jumpPhysics(jump_start_time);
	y_offset = resting_y - distance;

}
double AnimatedSprite::jumpPhysics(int start_time_of_jump)
{
	double elapsed_time = SDL_GetTicks() - start_time_of_jump;
	double curr_time_sec = (elapsed_time / 1000);

	double distance = ( ( (jump_velocity * curr_time_sec) + (0.5 * ACC_GRAVITY * curr_time_sec*curr_time_sec) )  * PIXLES_PER_FOOT  ) ;


	return distance; // this tells us the distance from the baseline, which is where the jump starts. 
}
void AnimatedSprite::loadSprite()
{
	sprite_list[IDLE_FRAMES]->setClipArray(7,0,0,70,115);
	sprite_list[WALKING_FRAMES_L] ->setClipArray(7,0,0,70,115);
	sprite_list[WALKING_FRAMES_R]->setClipArray(7,0,0,70,115);
}
