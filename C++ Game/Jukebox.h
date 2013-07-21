#pragma once
#include "SDL_mixer.h"


class Jukebox
{
public:
	Mix_Music* music;
	Mix_Chunk* jump;
	
	Jukebox();
	~Jukebox();
	void loadSong(char* filename);
	Mix_Chunk* loadSoundEffect(char* filename);

private:

protected:

};