#pragma once
#include "SDL.h"
#include <SDL_image.h>
#include <string>
#include <vector>

class GameWindow
{
public:
	bool init(const char* title, int x, int y, int width, int height, bool fullscreen);

	static bool isRunning;
private:
	SDL_Window* window;
};
