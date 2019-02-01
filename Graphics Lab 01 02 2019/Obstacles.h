#pragma once
#include <SFML/Graphics.hpp>

class Obstacles
{
	sf::RectangleShape body;

	enum direction
	{
		left,
		right
	};

	direction moveDirection;

	sf::Vector2f velocity;
	float moveSpeed;

	int timeToLive;

	bool onScreen;

public:
	Obstacles();
	~Obstacles();

	void spawn();
	void move();

	inline void reset() { onScreen = false; }

	inline bool isOnScreen() { return onScreen; }
	inline sf::RectangleShape getBody() { return body; }
};