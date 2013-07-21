#pragma once
#include "SDL.h"
#include "Timer.h"
#include "Jukebox.h"
#include "FrameRate.h"
#include "Hero.h"
#include "SpriteDirector.h"

class System
{

public:
	//MEMBER VARIABLES
	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 480;
	static const int SCREEN_BPP = 32;

	SDL_Surface* screen;
	SDL_Event action;
	Timer* timer;
	Jukebox* jukebox;
	FrameRate* framerate;
	SpriteDirector* sprite_director;
	bool fullscreen;

	//PROTOTYPES
	System();
	~System();
	void delaySystem(int time);
	void update();
	void setWindow();
	bool init();
	void loadJukeBox();
	void toggleFullscreen();
	void toggleWindowed();
private:

protected:
};
