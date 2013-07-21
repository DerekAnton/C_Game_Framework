#include "Keyboard.h"
#include "SpriteDirector.h"



Keyboard::Keyboard()
{
	action = IDLE;
	left_press = false;
	right_press= false;
}
Keyboard::~Keyboard()
{
}
void Keyboard::checkKeys(System* system)
{
	if( system->action.type == SDL_KEYDOWN )
	{
		switch(system->action.key.keysym.sym)
		{
			case SDLK_UP:
				break;
			case SDLK_DOWN: 
				break;
			case SDLK_LEFT: 
				
				leftDown(system);
			    break;

			case SDLK_RIGHT:
				
				rightDown(system);
				break;

			case SDLK_LSHIFT: 
				
				{ // this is a stack frame variable, for use of local hero
					Hero* hero = system->sprite_director->getHero();
				
					if(!(hero->jumping) )
					{
						Mix_PlayChannel( -1, system->jukebox->jump, 0 ); 
						hero->jump_start_time = SDL_GetTicks();
						hero->jumping = true;				
					}
				}
				break;
		}			 
	} 
	else if( system->action.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( system->action.key.keysym.sym )
        {
            case SDLK_DOWN: 
				break;
			case SDLK_LEFT: 
				
				leftUp(system);				
				break;

			case SDLK_RIGHT: 
			
				rightUp(system);
				break;

			case SDLK_LSHIFT: 
				break; 
        }        
    }
	
}
void Keyboard::leftDown(System* system)
{
	
	if(!left_press) 
		left_press = true;
	
	Hero* hero = system->sprite_director->getHero();
				
	if(left_press && !right_press)
	{
		hero->x_distance = -(hero->speed);
		hero->current_sprite = hero->WALKING_FRAMES_L;
		action = LEFT;
	}
	if(left_press && right_press)
	{
		hero->x_distance = -(hero->speed);
		hero->current_sprite = hero->WALKING_FRAMES_L;
		action = LEFT;
	}
}

void Keyboard::rightDown(System* system)
{
	if(!right_press) 
		right_press = true;

	Hero* hero = system->sprite_director->getHero();

	if(right_press && !left_press)
	{
		hero->x_distance = hero->speed; 
		hero->current_sprite = hero->WALKING_FRAMES_R;
		action = RIGHT;
	}
	if(right_press && left_press)
	{
		hero->x_distance = hero->speed; 
		hero->current_sprite = hero->WALKING_FRAMES_R;
		action = RIGHT;
	}

}
void Keyboard::leftUp(System* system)
{
	Hero* hero = system->sprite_director->getHero();

	if(left_press && !right_press)
	{
		hero->x_distance = 0;            
		hero->current_sprite = hero->IDLE_FRAMES;  
		action = IDLE;
	}
	if(left_press && right_press)
	{
		hero->x_distance = hero->speed;
		hero->current_sprite = hero->WALKING_FRAMES_R; 
		action = RIGHT;
	}
	left_press = false;

}
void Keyboard::rightUp(System* system)
{
	Hero* hero = system->sprite_director->getHero();

	if(right_press && !left_press)
	{
		hero->x_distance -= hero->speed;  
		hero->current_sprite = hero->IDLE_FRAMES; 
		action = IDLE;
	}
	if(left_press && right_press)
	{
			hero->x_distance = -(hero->speed);
			hero->current_sprite = hero->WALKING_FRAMES_L; 
			action = LEFT;
	}
	right_press = false;
					
}