#include "Timer.h"

Timer::Timer()
{
	running_timer = false;
	quit_timer = true;
	start_time = 0;
	end_time = 0;
}
Timer::~Timer()
{

}

void Timer::getStartTime()
{
	running_timer = true;
	quit_timer = false;
	start_time = SDL_GetTicks();
}
void Timer::getEndTime()
{
	running_timer = false;
	quit_timer = true;
	end_time = SDL_GetTicks();
}
void Timer::calcTime()
{
	timed_value = end_time - start_time;
}

void Timer::resetTimer()
{
	running_timer = false;
	quit_timer = true;

	timed_value = 0;
	end_time = 0;
	start_time = 0;
}
