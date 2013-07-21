#include "Image.h"
#include "Collision.h"

class StaticSprite
{
public: 
	Image* image;
	Collision* collision;

	StaticSprite(char* img_name);
	~StaticSprite();

private:

protected:

};