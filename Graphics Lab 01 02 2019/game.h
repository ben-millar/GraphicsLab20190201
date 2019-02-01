/// <summary>
/// Author: Ben Millar – C00236772
/// Date:
/// Estimated time to complete: 2 hours
/// Session 1 Start: 09:30 End:
/// </summary>

#pragma once
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Ball.h"
#include "Obstacles.h"

class Game
{
public:

	Game();
	~Game();
	void run();

private:

	// ++++++++++ Methods ++++++++++

	void processEvents(); // checks for all input
	void setupFontAndText(); // set up all text
	void setupSounds(); // set up all sounds
	void setupObjects(); // set up all sfml objects
	void setupSprites(); // set up all images
	void update(sf::Time t_deltaTime); // main update method
	void render(); // renders framebuffer

	// +++++++++++++++++++++++++++++

	// +++++++++ Variables +++++++++

	bool m_exitGame = false; // control exiting game

	static const int NUM_OF_OBSTACLES = 10;

	int obstacleStep = 0;

	// +++++++++++++++++++++++++++++

	// ++++++++++ Objects ++++++++++

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont;

	sf::Clock obstacleClock;
	sf::Time obstacleTimer;

	Ball m_ball;
	Obstacles m_obstacle[NUM_OF_OBSTACLES];

	// +++++++++++++++++++++++++++++
};

#endif // !GAME