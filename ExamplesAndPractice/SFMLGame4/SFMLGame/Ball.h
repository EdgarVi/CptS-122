#pragma once
#include <SFML/Graphics.hpp>

// will finish the ball class on Wednesday, 4/12
class Ball : public sf::CircleShape {
public:
	Ball(const sf::Color & color, const float & radius,
		const sf::Vector2f & position) {
		this->setFillColor(color);
		this->setRadius(radius);
		this->setPosition(position);


	}



private:
	


};
