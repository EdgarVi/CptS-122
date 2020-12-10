#include <list>
#include "SFML/Graphics.hpp"
#include "Body.h"
using namespace std;

//class Body;

class Head {
public:

	Head(sf::RenderWindow&);

	void move(const int &newDirection);
	void draw();

	void grow();
	void shrink();

	list<Body> getBodies();

	int getX();
	int getY();

private:

	std::list<Body> _head; //list of blocks
	sf::RenderWindow * _win;
	enum direction { UP, RIGHT, DOWN, LEFT };
	int _direction;
	
};