#include "FrameRate.h"


FrameRate::FrameRate()
{
	cap = false;
	current_frame = 0;
	fps = new Timer();
}

FrameRate::~FrameRate()
{
	delete fps;
}
void FrameRate::sleepFrames()
{
	if( ( cap == true ) && ( fps->timed_value < 1000 / FRAMES_PER_SECOND ) )
        {
            //Sleep the remaining frame time
			SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps->timed_value );
        }
}
