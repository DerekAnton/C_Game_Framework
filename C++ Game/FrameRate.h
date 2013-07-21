#pragma once
#include "SDL.h"
#include "Timer.h"

class FrameRate
{
public:
	static const int FRAMES_PER_SECOND = 20;
	int current_frame;
	bool cap;

	Timer* fps;
	
	FrameRate();
	~FrameRate();
	void sleepFrames();
private:

protected:

};