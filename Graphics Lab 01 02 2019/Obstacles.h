#pragma once
#include <SFML/Graphics.hpp>

class Obstacles
{
	sf::RectangleShape body;

	sf::Vector2f velocity;
	float moveSpeed;

	enum direction
	{
		left,
		right
	};

	direction moveDirection;

	bool onScreen;

public:
	Obstacles();
	~Obstacles();

	void spawn();
	inline void move() { body.move(velocity); }

	inline bool isOnScreen() { return onScreen; }
	inline sf::RectangleShape getBody() { return body; }
};