#pragma once
#include "SDL.h"
#include "Image.h"
#include "Collision.h"
//#include "SpriteDirector.h" BLOWS UP CODE (circular refference)


class AnimatedSprite
{
public:
	
	static const int ACC_GRAVITY = -32;
	static const int PIXLES_PER_FOOT = 20; // conversion factor from pixles to feet.
	static const int MAX_SPRITE_IMAGES = 8;

	enum currentSpriteAction { WALKING_FRAMES_L, WALKING_FRAMES_R, IDLE_FRAMES};
	currentSpriteAction current_sprite;


	int sprite_width; 
	int sprite_height;
	int speed; 
	int pixles_per_foot;
	int jump_velocity;
	int acc_gravity;
	
	int jump_start_time;

	int x_offset; // actual x pos
	int y_offset; // actual y pos

	int x_distance; // the distance to move
	int y_distance; // same ^

	int resting_y; // the y that stores the y before we jumped, so that we can check against it

	int currentFrame;
	int frameLimiter;

	int current_sprite_pos;
	int max_frame;

	bool jumping;

	int last_collision;

	
	SDL_Rect* current_rect;
	
	Collision* collision;

	Image* displayedImage;
	Image* sprite_list[AnimatedSprite::MAX_SPRITE_IMAGES];

	AnimatedSprite();
	~AnimatedSprite();
	
	bool move();
	void jump();
	double jumpPhysics(int start_time_of_jump);
	void loadSprite();

	void init(int width, int height, int speed, int jump_vel);

private:

protected:

};