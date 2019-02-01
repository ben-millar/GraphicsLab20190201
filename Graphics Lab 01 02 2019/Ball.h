#pragma once
#include <SFML/Graphics.hpp>
class Ball
{
	sf::RectangleShape body;

	sf::Vector2f velocity;
	float moveSpeed;

	enum move
	{
		top = 1,
		bottom = -1
	};

	move moveState;

	bool moving;

public:
	Ball();
	~Ball();

	inline sf::RectangleShape getBody() { return body; }

	void start();
	void move();
	void stop();
};

