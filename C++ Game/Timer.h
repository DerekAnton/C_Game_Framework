#pragma once
#include "SDL.h"

class Timer
{
public:
	Uint32 start_time;
	Uint32 end_time;
	Uint32 timed_value;
	bool quit_timer;
	bool running_timer;

	Timer();
	~Timer();

	void getStartTime();
	void getEndTime();
	void resetTimer();
	void calcTime();

private:

protected:

};
/*//practical application of the timer in use, but not nessisary for anything.
			if(system->timer->runningTimer == false && system->timer->quitTimer == true)
			{
				system->timer->startTime = system->timer->getStartTime();
			}
			else
			{
				system->timer->endTime = system->timer->getEndTime();
				Uint32 temp = 0;
				temp = system->timer->endTime - system->timer->startTime;
			}*/