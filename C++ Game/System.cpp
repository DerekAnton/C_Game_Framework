#include "System.h"	
#include "SDL.h"
#include "SDL_mixer.h"


System::System()
{
	init();

	timer = new Timer();
	jukebox = new Jukebox();
	framerate = new FrameRate();
	loadJukeBox();
	
}
System::~System()
{
	delete timer;
	delete jukebox;
	delete framerate;
	SDL_FreeSurface(screen);
}

void System::delaySystem(int time)
{
	SDL_Delay(time);
}

void System::update()
{
	SDL_Flip(screen);
}
void System::setWindow()
{
	if(!fullscreen)
		screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
	else
		screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
}
bool System::init()
{
	fullscreen = false;
	
	 if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;    
    }

	 SDL_WM_SetCaption("Steamboy", NULL);
	 setWindow();

	  if( screen == NULL )
    {
        return false;    
    }
	  if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;    
    }
	  return true;
}
void System::loadJukeBox()
{
	
	jukebox->loadSong("Soundtrack.wav");
	//*note loadsoundeffect RETURNS a sound file, which must then be stored into jukebox's 'jump' variable
	jukebox->jump = jukebox->loadSoundEffect("jump.wav");
}
void System::toggleFullscreen()
{
	fullscreen = true;
}
void System::toggleWindowed()
{
	fullscreen = false;
}
