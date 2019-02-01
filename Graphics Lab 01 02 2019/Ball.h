#pragma once
#include <SFML/Graphics.hpp>
class Ball
{
	sf::RectangleShape body;

	int score;

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
	inline int getScore() { return score; }

	void start();
	void move();
	void stop();

	void reset();
};