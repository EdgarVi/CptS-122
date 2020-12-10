#include "Body.h"

Body::Body(const int &x, const int &y)
{
	_x = x;
	_y = y;
}

int Body::getX()
{
	return _x;
}

int Body::getY()
{
	return _y;
}
