#pragma once
#include "SDL.h"
#include "SDL_image.h"


class Image
{
public:
	//Members
	SDL_Surface* img;
	SDL_Rect offset;
	SDL_Rect clip[7];
	int sprite_frame_limiter;

	//Protos
	Image(char* filename, int sprite_frame_limiter = -1);
	~Image();
	void loadImg(char* filename);
	void drawImg(int x, int y, SDL_Surface* img, SDL_Surface* screen, SDL_Rect* newclip);
	void setClipArray(int sizeOfArray, int x, int y, int width, int heigth);
private:

protected:

};