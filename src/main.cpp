#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "GameWindow.h"
#include "Renderer.h"
#include "objects/ObjectManager.h"
#include "objects/GameObject.h"
#include "objects/BasicGameObject.h"

#include <iostream>

GameWindow gameWindow;
ObjectManager objectManager;
Renderer renderer;

int main(int argc, char* args[])
{
	if (gameWindow.init("Bread Clicker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false))
	{
		ObjectManager::createObject<GameObject>(std::uint16_t(0), "res/box.png", 20, 0);
		ObjectManager::createObject<BasicGameObject>(std::uint16_t(0), 20, 60);
		while (gameWindow.isRunning)
		{
			gameWindow.handleEvents();
			renderer.clear();
			objectManager.proccessObjects();
        	renderer.resetColor();
			renderer.draw();
			SDL_Delay(16);
		}
	}
	return 0;
}