#include "Obstacles.h"


Obstacles::Obstacles()
{
	body.setPosition({ -100.0f,-100.0f });
	float size = static_cast<float>(rand() % 41 + 30); // random between 30 - 60
	body.setSize({ size,size });

	moveSpeed = static_cast<float>(rand() % 4 + 2); // random between 2 - 5

	onScreen = false;
}


Obstacles::~Obstacles()
{
}

void Obstacles::spawn()
{
	moveDirection = direction(rand() % 2); // random direction left or right
	float yPos = static_cast<float>(rand() % 401 + 50); // random between 50 - 450
	float xPos = 0.0f;
	velocity = { 0.0f,0.0f };

	if (moveDirection == left)
	{
		xPos = 1100.0f;
		velocity = { -moveSpeed, 0.0f };
	}
	else
	{
		xPos = -100.0f;
		velocity = { moveSpeed, 0.0f };
	}
	
	body.setPosition(xPos, yPos);

	onScreen = true;
}