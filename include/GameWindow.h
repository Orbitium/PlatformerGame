#pragma once
#include "SDL.h"
#include <SDL_image.h>
#include <string>
#include <vector>

class GameObject;
class GameWindow
{
public:
	bool init(const char* title, int x, int y, int width, int height, bool fullscreen);
	void handleEvents();

	bool isRunning = true;
private:
	SDL_Event event;
	SDL_Window* window;
	//TileManager tileManager;
};
