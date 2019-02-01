#include "Ball.h"


Ball::Ball()
{
	body.setSize({ 40.0f, 40.0f });
	body.setFillColor(sf::Color::Red);
	body.setOrigin({ 20.0f,20.0f });
	body.setPosition({ 500.0f,0.0f + 20.0f });

	velocity = { 0.0f,0.0f };
	moveSpeed = 7.0f;

	moveState = top;
	moving = false;

	score = 0;
}


Ball::~Ball()
{
}

void Ball::start()
{
	if (moving == false)
	{
		velocity = { 0.0f, moveSpeed*moveState };
		moving = true;
	}
}

void Ball::move()
{
	if (moving == true)
	{
		body.move({ velocity });
		if (body.getPosition().y < 25.0f || body.getPosition().y > 575.0f)
		{
			stop();
		}
	}
}

void Ball::stop()
{
	velocity = { 0.0f,0.0f };
	(moveState == top) ? moveState = bottom : moveState = top;
	score++;
	moving = false;
}