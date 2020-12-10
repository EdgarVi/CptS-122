#include "SFML/Graphics.hpp"

using namespace std;

class Target
{
public:
	Target(sf::RenderWindow &Win );

	void spawn(const float &x, const float &y);

	float getX();
	float getY();

private:
	sf::RenderWindow *_win;


	float _x;
	float _y;
};