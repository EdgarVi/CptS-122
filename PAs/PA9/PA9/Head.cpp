#include "Head.h"

Head::Head(sf::RenderWindow &Win)
{
	_win = &Win;
	
	_direction = RIGHT;

	// Draws the initial head
	_head.push_front(Body(25, 0));
	_head.push_front(Body(50, 0));
}

void Head::move(const int &newDirection)
{
	shrink();

	//All following blocks replace the block in front of them
	if (newDirection == UP)
	{
		if (_direction != DOWN)
		{
			_head.push_front(Body(_head.front().getX(), _head.front().getY() - 25));
			_direction = UP;
		}
		else
		{
			_head.push_front(Body(_head.front().getX(), _head.front().getY() + 25));
		}
	}

	else if (newDirection == RIGHT)
	{
		if (_direction != LEFT)
		{
			_head.push_front(Body(_head.front().getX() + 25, _head.front().getY()));
			_direction = RIGHT;
		}
		else
		{
			_head.push_front(Body(_head.front().getX() - 25, _head.front().getY()));
		}
	}

	else if (newDirection == DOWN)
	{
		if (_direction != UP)
		{
			_head.push_front(Body(_head.front().getX(), _head.front().getY() + 25));
			_direction = DOWN;
		}
		else
		{
			_head.push_front(Body(_head.front().getX(), _head.front().getY() - 25));
		}

	}

	else if (newDirection == LEFT)
	{
		if (_direction != RIGHT)
		{
			_head.push_front(Body(_head.front().getX() - 25, _head.front().getY()));
			_direction = LEFT;
		}
		else
		{
			_head.push_front(Body(_head.front().getX() + 25, _head.front().getY()));
		}
	}
}

void Head::draw()
{

	//draw each block individually
	for (list<Body>::iterator it = _head.begin(); it != _head.end(); it++)
	{
		float x = it->getX();
		float y = it->getY();


		sf::RectangleShape body(sf::Vector2f(20, 20));
		body.setFillColor(sf::Color::Red);
		
		body.move(x, y);

		_win->draw(body);
	}
}

void Head::grow()
{
	//place block at end of body
	_head.push_back(Body(_head.back().getX(), _head.back().getY()));
}

void Head::shrink()
{
	//delete block
	_head.pop_back();
}

list<Body> Head::getBodies()
{
	//return a block in the list
	return _head;
}

int Head::getX() 
{
	//return x coord of head
	return _head.front().getX();
}

int Head::getY() 
{
	//return y coord of head
	return _head.front().getY();
}
