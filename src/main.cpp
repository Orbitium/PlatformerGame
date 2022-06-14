#define SDL_MAIN_HANDLED

#include "GameWindow.h"
#include "Renderer.h"
#include "EventHandler.h"
#include "objects/ObjectManager.h"
#include "tiles/TileManager.h"
#include "objects/Player.h"
#include "HitboxManager.h"
#include "tiles/GrassTile.h"

#include <iostream>

bool GameWindow::isRunning =  true;

GameWindow gameWindow;
Renderer renderer;
EventHandler eventHandler;
ObjectManager objectManager;
TileManager tileManager;
HitboxManager hitboxManager;

int main(int argc, char* args[])
{
	if (gameWindow.init("Platformer Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false))
	{
		objectManager.initObjects();
		tileManager.createLevel(1);
		int playerID = ObjectManager::createObject<Player>(2, 10, 20);
		while (gameWindow.isRunning)
		{
			eventHandler.handleEvents();
			renderer.clear();
			objectManager.proccessObjects();
			hitboxManager.checkCollisions();
        	renderer.resetColor();
			renderer.draw();
			objectManager.clearObjects();
			SDL_Delay(16.6); //Make game to ~60 FPS
		}
	}
	return 0;
}