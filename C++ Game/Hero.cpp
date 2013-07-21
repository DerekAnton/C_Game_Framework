#pragma once
#include "Hero.h"
#include  "SDL.h"


Hero::Hero()
{
	x_offset = 100;
	y_offset = 335;

	resting_y = y_offset;

	x_distance = 0;
	y_distance = 0;

	currentFrame = 0;
	frameLimiter = 0;

	current_sprite_pos = 0;
	max_frame = 0;

	jump_start_time = 0;
	
	jumping = false;

	init(70, 118, 5, 15);     // width height, speed, jump velocity
	
	current_sprite = IDLE_FRAMES;

	sprite_list[IDLE_FRAMES] = new Image("SizedHeroSprites.png", 0);
	sprite_list[WALKING_FRAMES_L] = new Image("WalkingSpriteL.png", 0);
	sprite_list[WALKING_FRAMES_R] = new Image("WalkingSpriteR.png", 0);
	
	displayedImage = sprite_list[IDLE_FRAMES] ;

	loadSprite();

	collision = new Collision(sprite_list[IDLE_FRAMES] );

}

Hero::~Hero()
{
	for(int counter = 0; counter < MAX_SPRITE_IMAGES; counter++)
	{
		if(sprite_list[counter] != NULL)
		{
			delete sprite_list[counter];
			sprite_list[counter] = NULL;
		}
	}
}

void Hero::displayHero(SDL_Surface* screen)
{
	
	if(current_sprite == WALKING_FRAMES_R || current_sprite == WALKING_FRAMES_L) 
		max_frame = 5;  
	if(current_sprite == IDLE_FRAMES)
		max_frame = 6;

	if(currentFrame > max_frame) 
		currentFrame = 0;  // allows the chocie between 7 or 6 frames in length (walking and idle sprite sheet length)
	

	if(current_sprite == WALKING_FRAMES_L)
	{
		displayedImage = sprite_list[WALKING_FRAMES_L];
		current_rect = &(sprite_list[WALKING_FRAMES_L]->clip[currentFrame]);
		collision->hitbox = *current_rect;
	}
	if(current_sprite == WALKING_FRAMES_R)
	{
		displayedImage = sprite_list[WALKING_FRAMES_R];
		current_rect = &(sprite_list[WALKING_FRAMES_R]->clip[currentFrame]);
		collision->hitbox = *current_rect;
	}
	if(current_sprite == IDLE_FRAMES)
	{
		displayedImage = sprite_list[IDLE_FRAMES] ;
		current_rect = &(sprite_list[IDLE_FRAMES]->clip[currentFrame]);
		collision->hitbox = *current_rect;
	}

	displayedImage->drawImg(x_offset,y_offset,displayedImage->img,screen, current_rect); // actually draws the image to the screen
}


