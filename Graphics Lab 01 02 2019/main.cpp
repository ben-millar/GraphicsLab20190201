/// <summary>
/// Author: Ben Millar � C00236772
/// Date: 01/02/2019
/// Time to complete: 3 hours
/// </summary>

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif


#include "game.h"
#include <SFML\Graphics.hpp>
#include <string>


int main()
{
	srand(static_cast<unsigned>(time(nullptr))); // seed RNG
	Game game;
	game.run();
	return EXIT_SUCCESS;
}