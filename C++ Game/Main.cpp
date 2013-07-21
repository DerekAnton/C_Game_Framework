#include "Main.h"
#include "SDL.h"
#include "SDL_mixer.h"
#include "Image.h"
#include "System.h"
#include "SpriteDirector.h"
#include "SDL_image.h"
#include "Jukebox.h"
#include "Keyboard.h"
#include "StaticSpriteDirector.h"



int main( int argc, char* args[] )
{
	bool quit = false; // nessisary to break the action loop
	bool initFlag = true; // flag that is thrown is init failed
	const int FPS = 40;
	/*
	 * System obj has everything. wraps the followinf objs:
	 */

	System* system = new System(); 

	SpriteDirector* sprites = new SpriteDirector();


	//system->hero = (Hero*) sprites->ani_sprite_dir->animated_array[AnimatedSpriteDirector::HERO];

	/*
	 * Test init, if fails, end program
	 */
	initFlag = system->init();
	if(initFlag == false)
	{
		return 0;
	}
	
	sprites->screen = system->screen;

	system->sprite_director = sprites;

	/*
	 *  Create keyboard and static_sprite directors
	 */

	Keyboard* keyboard = new Keyboard();

	/*
	 * Using directors (hero and static_sprite) to add nessisary sprites to thier image objects
	 */

	sprites->static_sprite_dir->static_array[StaticSpriteDirector::BACKGROUND]->image->drawImg(0,0,sprites->static_sprite_dir->static_array[StaticSpriteDirector::BACKGROUND]->image->img, system->screen, NULL);

	system->update();

	/*
	 * Begin Action Loop
	 */
	int start_time = SDL_GetTicks();

	while(quit == false)
	{
		while( (SDL_GetTicks() - start_time) < (1000 / FPS) ) 
		{
				while(SDL_PollEvent(&(system->action)))
				{
					keyboard->checkKeys(system);

					if(system->action.type == SDL_QUIT)
					{
						quit = true;
					}
				}
		}
		if( sprites->moveAll() ) // if the frameLimit is time to move, 
			{
				sprites->static_sprite_dir->static_array[StaticSpriteDirector::BACKGROUND]->image->drawImg(0,0,sprites->static_sprite_dir->static_array[StaticSpriteDirector::BACKGROUND]->image->img, system->screen, NULL); // redraws the screen
				sprites->static_sprite_dir->static_array[StaticSpriteDirector::BACKGROUND]->image->drawImg(0, 450, sprites->static_sprite_dir->static_array[StaticSpriteDirector::GROUND]->image->img, system->screen, NULL);
				sprites->static_sprite_dir->static_array[StaticSpriteDirector::BACKGROUND]->image->drawImg(500, 390, sprites->static_sprite_dir->static_array[StaticSpriteDirector::WALL]->image->img, system->screen, NULL);
				//system->hero->displayHero(system->screen);// draws the hero to the screen
				
				sprites->displayAll();

				system->update();
			} 
			start_time = SDL_GetTicks();
	}
	
	    
    /*
	 * Garbage Collection
	 */
	Mix_FreeMusic(system->jukebox->music);
	Mix_FreeChunk(system->jukebox->jump);
	delete sprites;
	delete keyboard;
    delete system;

    SDL_Quit();

    return 0;    
}