#include "Target.h"

Target::Target(sf::RenderWindow & Win)
{
	_win = &Win;
}

void Target::spawn(const float &x, const float &y)
{

	//new target is made
	sf::RectangleShape body(sf::Vector2f(20, 20));
	body.setFillColor(sf::Color::Green);

	body.move(x, y);

	_x = x;
	_y = y;

	_win->draw(body);
}

float Target::getX()
{
	return _x;
}

float Target::getY()
{
	return _y;
}
