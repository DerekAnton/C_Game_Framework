
#include "System.h"
#include "Hero.h"


class Keyboard
{
public:
	
	 enum current_action{LEFT, RIGHT, IDLE, UP, DOWN};
	 current_action action; 
	
	bool left_press;
	bool right_press;

	Keyboard();
	~Keyboard();
	void checkKeys(System* system);
	void leftDown(System* system);
	void rightDown(System* system);
	void leftUp(System* system);
	void rightUp(System* system);
private:

protected:

};
