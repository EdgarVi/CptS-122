#include "Application.h"

#include <iostream>
#include <list>
#include <iterator>

#include <SFML/Graphics.hpp>

#include "Head.h"
#include "Target.h"

void Application::startGame()
{

	sf::RenderWindow window(sf::VideoMode(750, 650), "Cool Title", sf::Style::Close);
	window.setFramerateLimit(12);


	//starting block
	Head head(window);

	//blocks that will build up the body
	list<Body> bodies;
	list<Body>::iterator it;

	// Direction
	enum direction { UP, RIGHT, DOWN, LEFT };
	int direction = RIGHT;

	// target
	Target target(window);

	// Tells if we need to respawn a target
	bool mustSpawnTarget = true;

	// Coords of the target
	int targetX;
	int targetY;

	sf::Texture texture;
	if (!texture.loadFromFile("Resources/Images/window.jpg", sf::IntRect(0, 0, 750, 650)))
	{
		cout << "Image could not load" << endl;
	}

	sf::Sprite background;
	background.setTexture(texture);

	// Loading the font that will be used for the text components of the program
	sf::Font font;
	if (!font.loadFromFile("Resources/Other/OpenSans-Regular.ttf"))
	{
		cout << "Font was not loaded" << endl;
	}

	// Text for disiplaying current score to the screen
	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setString("Your Score:");
	scoreText.setCharacterSize(24);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setOutlineColor(sf::Color::Black);
	scoreText.setOutlineThickness(5);

	// Text for displaying instructions to the screen, goes away after the first up key is pressed
	sf::Text instructionsText;
	instructionsText.setFont(font);
	instructionsText.setString("Classic Snake Game: Use directional keys to move \n and don't run into a wall or into yourself!");
	instructionsText.setCharacterSize(24);
	instructionsText.setFillColor(sf::Color::White);
	instructionsText.setOutlineColor(sf::Color::Black);
	instructionsText.setOutlineThickness(5);
	instructionsText.setPosition(100, window.getSize().y / 2);


	bool instructions = true; // Bool flag that tells the program when to display the instructions


	int targetCounter = 0; //Integer variable that will be incremented by 1 each time a target is hit

	//Game loop
	while (window.isOpen()) {


		//Text for displaying target number
		sf::Text targetText;
		targetText.setFont(font);
		targetText.setString(to_string(targetCounter));
		targetText.setCharacterSize(24);
		targetText.setFillColor(sf::Color::White);
		targetText.setOutlineColor(sf::Color::Black);
		targetText.setOutlineThickness(5);
		targetText.setPosition(132, 0);

		window.clear();

		window.draw(background);

		if (instructions)
		{
			window.draw(instructionsText);
		}

		window.draw(scoreText);
		window.draw(targetText);

		sf::Event Event;


		while (window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
			{
				window.close();
			}

			// Determine the direction of the snake
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Right))
			{
				direction = RIGHT;
				instructions = false;
			}
			else if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Left))
			{
				direction = LEFT;
				instructions = false;
			}
			else if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Up))
			{
				direction = UP;
				instructions = false;
			}
			else if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Down))
			{
				direction = DOWN;
				instructions = false;
			}
		}


		//spawn target if neccessary
		if (mustSpawnTarget)
		{
			bool safe = true;

			// We make sure that it doesn't spawn on the snake
			do
			{
				targetX = (rand() % 30) * 25;
				targetY = (rand() % 25) * 25;

				bodies = head.getBodies();

				for (it = bodies.begin(); it != bodies.end(); it++)
				{
					if (it->getX() == targetX && it->getY() == targetY)
					{
						safe = false;
						break;
					}
					else
					{
						safe = true;
					}
				}
			} while (safe != true);

			mustSpawnTarget = false;
		}

		target.spawn(targetX, targetY);

		head.move(direction);
		head.draw();


		// Detects if the snake hits the bounds of the board
		if (head.getX() >= 750 || head.getX() < 0 || head.getY() >= 625 || head.getY() < 0)
		{
			window.close();
		}


		// Detects if the snake hits a target
		if (head.getX() == target.getX() && head.getY() == target.getY())
		{
			mustSpawnTarget = true;

			head.grow();

			targetCounter = targetCounter + 1;
		}


		//Detects if the snake hits himself
		bodies = head.getBodies();
		it = bodies.begin();

		it++; // Since we know the last inserted block is the same position as the snake's head, we skip it

		for (it; it != bodies.end(); it++)
		{
			if (it->getX() == head.getX() && it->getY() == head.getY())
			{
				window.close();
			}
		}


		window.display();
	}
}
