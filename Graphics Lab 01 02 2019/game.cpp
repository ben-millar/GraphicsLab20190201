/// <summary>
/// Author: Ben Millar – C00236772
/// Date:
/// Estimated time to complete:
/// Session 1 Start: End:
/// </summary>

#include "game.h"
#include <iostream>


/// <summary>
/// default construcor
/// pass parameters for sfml window, setup m_exitGame
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 1000, 600, 32 }, "Rectangle Dodge" },
	m_exitGame{ false } //when true game will exit
{
	setupFontAndText(); // load font 
	setupObjects(); // set sfml object parameters
	setupSounds(); // load and setup sound buffers
}

/// <summary>
/// default destructor for game, nothing to release
/// </summary>
Game::~Game()
{
}

/// <summary>
/// game loop running at 60fps
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	srand(static_cast<unsigned>(time(nullptr)));
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}

			if (sf::Keyboard::Space == event.key.code)
			{
				m_ball.start();
			}
		}
	}
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_scoreText.setFont(m_ArialBlackfont);
	m_gameOverText.setFont(m_ArialBlackfont);
	m_gameOverScoreText.setFont(m_ArialBlackfont);

	m_scoreText.setFillColor(sf::Color(255, 255, 255, 192));
	m_scoreText.setCharacterSize(150U);
	m_scoreText.setPosition(450.0f, 230.0f);

	m_gameOverText.setFillColor(sf::Color::White);
	m_gameOverText.setCharacterSize(64U);
	m_gameOverText.setPosition(300.0f,200.0f);
	m_gameOverText.setString("GAME OVER");

	m_gameOverScoreText.setFillColor(sf::Color::White);
	m_gameOverScoreText.setCharacterSize(32U);
	m_gameOverScoreText.setPosition(335.0f, 270.0f);
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Game::setupSounds()
{
	
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///<summary>
/// sets up attributes for all SFML objects
///</summary>
void Game::setupObjects()
{
	obstacleClock.restart();
	obstacleTimer = sf::seconds(3.0f);

}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}

	if (gameState == gameplay)
	{
		obstacleHandler();
		move();
	}
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Game::obstacleHandler()
{
	if (obstacleClock.getElapsedTime() > obstacleTimer + sf::seconds(rand() % 4 - 1.5))
	{
		obstacleClock.restart();
		m_obstacle[obstacleStep%NUM_OF_OBSTACLES].spawn();
		obstacleStep++;
	}
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Game::move()
{
	m_ball.move();

	for (int i = 0; i < NUM_OF_OBSTACLES; i++)
	{
		if (m_obstacle[i].isOnScreen() == true) m_obstacle[i].move();
	}

	checkCollisions();
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Game::checkCollisions()
{
	for (int i = 0; i < NUM_OF_OBSTACLES; i++)
	{
		sf::RectangleShape obstacle = m_obstacle[i].getBody();
		sf::RectangleShape player = m_ball.getBody();

		if (obstacle.getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			gameState = gameOver;
		}
	}
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);

	if (gameState == gameplay)
	{
		m_scoreText.setString(std::to_string(m_ball.getScore()));
		m_window.draw(m_scoreText);

		m_window.draw(m_ball.getBody());

		for (int i = 0; i < NUM_OF_OBSTACLES; i++)
		{
			if (m_obstacle[i].isOnScreen() == true) m_window.draw(m_obstacle[i].getBody());
		}

	}
	else if (gameState == gameOver)
	{
		m_gameOverScoreText.setString("You scored " + std::to_string(m_ball.getScore()) + " points");

		m_window.draw(m_gameOverText);
		m_window.draw(m_gameOverScoreText);
	}

	m_window.display();
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++