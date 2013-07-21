#include "Jukebox.h"



Jukebox::Jukebox()
{
	music = NULL;
	jump = NULL;
}

Jukebox::~Jukebox()
{
	
}

void Jukebox::loadSong(char* filename)
{
	music = Mix_LoadMUS(filename);
	Mix_PlayMusic( music, -1 );
}
Mix_Chunk* Jukebox::loadSoundEffect(char* filename)
{
	Mix_Chunk* temp = Mix_LoadWAV(filename);
	return temp;
}