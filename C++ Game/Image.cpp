#pragma once
#include "Image.h"
#include "SDL_image.h"

Image::Image(char* filename, int sprite_frame_limiter)
{
	loadImg(filename);	
	this->sprite_frame_limiter = sprite_frame_limiter;
}
Image::~Image()
{
	SDL_FreeSurface(img);
}
void Image::loadImg(char* filename)
{
	SDL_Surface* loadedImage = NULL;

	loadedImage = IMG_Load(filename);

	if(loadedImage != NULL)
	{
		img = SDL_DisplayFormat(loadedImage);
		SDL_FreeSurface(loadedImage);

		Uint32 colorkey = SDL_MapRGB( img->format, 0, 0xFF, 0xFF );
		SDL_SetColorKey( img, SDL_SRCCOLORKEY, colorkey );
	}
}
void Image::drawImg(int x, int y, SDL_Surface* img, SDL_Surface* screen, SDL_Rect* newclip=NULL)
{
	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(img, newclip, screen, &offset);
}
void Image::setClipArray(int sizeOfArray, int x, int y, int width, int height)
{
	int xHolder = x;
	for(int counter = 0; counter < sizeOfArray; counter++)
	{
		clip[counter].x = xHolder;
		clip[counter].y = y;
		clip[counter].w = width;
		clip[counter].h = height;
		xHolder += width;
	}
}
