#pragma once
#include "SDL.h"
#include "Image.h"


class Environment
{
public: 

	/*
	 * for map creation, would it be smart to break up the entire screen into a grid, and then make a corresponding ascii character for each type of environment?
	 */
	SDL_Rect* hit_box;
	Image* sprite;

private: 

protected: 

};