#define SDL_MAIN_HANDLED

#include "GameWindow.h"
#include "Renderer.h"
#include "objects/ObjectManager.h"

#include <iostream>

GameWindow gameWindow;
ObjectManager objectManager;
Renderer renderer;

int main(int argc, char* args[])
{
	if (gameWindow.init("Bread Clicker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false))
	{
		objectManager.initObjects();
		while (gameWindow.isRunning)
		{
			gameWindow.handleEvents();
			renderer.clear();
			objectManager.proccessObjects();
        	renderer.resetColor();
			renderer.draw();
			SDL_Delay(16.6); //Make game to ~60 FPS
		}
	}
	return 0;
}