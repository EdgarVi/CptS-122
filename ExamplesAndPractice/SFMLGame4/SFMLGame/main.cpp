// This code expands on the tutorial code provided at:
// http://www.sfml-dev.org/tutorials/2.3/start-vc.php

// History:  - Created the ball for Pong - We also
//                 implemented unbounded movement for the ball and
//                 movement for paddle 1 based on the 's' keypress event
//           - Created the paddles for Pong - 
//                 we derived a Paddle class from a drawable
//                 sf::RectangleShape class

#include <SFML/Graphics.hpp>

#include <iostream>

using std::cout;
using std::endl;

#include "Paddle.h"
#include "Ball.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Pong");
	

	Paddle p1Paddle(sf::Color::Yellow, sf::Vector2f(10, 50), sf::Vector2f(0, 0)),
		 p2Paddle(sf::Color::Yellow, sf::Vector2f(10, 50), sf::Vector2f(window.getSize().x - 10, 0));
	
	Ball gameBall(sf::Color::Magenta, p1Paddle.getSize().x, *(new sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2)));
	bool p1IsPressed = false;
	bool p2IsPressed = false;

	int direction = 1;

	while (window.isOpen())
	{
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			if (event.type == sf::Event::KeyPressed)
			{
				if (!p1IsPressed && event.key.code == sf::Keyboard::S) // move paddle 1 down
				{
					p1IsPressed = true;
				}
				if (!p2IsPressed && event.key.code == sf::Keyboard::K) // move paddle 2 down
				{
					p2IsPressed = true;
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (p1IsPressed && event.key.code == sf::Keyboard::S) // move paddle 1 down
				{
					p1IsPressed = false;
				}
				if (p2IsPressed && event.key.code == sf::Keyboard::K) // move paddle 2 down
				{
					p2IsPressed = false;
				}
			}
		}

		if (p1IsPressed == true)
			p1Paddle.move(0, 0.1);
		if (p2IsPressed == true)
			p2Paddle.move(0, 0.1);

		window.clear();

		window.draw(p1Paddle);
		window.draw(p2Paddle);
		window.draw(gameBall);

		
		if (gameBall.getPosition().x >= window.getSize().x)
		{
			direction *= -1;
		}
		
		gameBall.move(direction * 0.1, direction * 0.1);

		cout << "Ball x pos: " << gameBall.getPosition().x << endl;

		window.display();


	}

	return 0;
}