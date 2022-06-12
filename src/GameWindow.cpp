#include <SDL_image.h>
#include <iostream>
#include <string>

#include "GameWindow.h"
#include "Renderer.h"

bool GameWindow::init(const char* title, int x, int y, int width, int height, bool fullscreen)
{
	bool initialized = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		initialized = false;
		std::cout << "SDL_Init: " << SDL_GetError() << std::endl;
	}
	if (TTF_Init() < 0) {
		std::cout << "TTF_Init: " << TTF_GetError() << std::endl;
		initialized = false;
	}
	if (IMG_Init(IMG_INIT_PNG) < 0)
	{
		std::cout << "IMG_Init: " << IMG_GetError() << std::endl;
		initialized = false;
	}
	window = SDL_CreateWindow(title, x, y, width, height, fullscreen);
	if (!window)
	{
		std::cout << "Window create error: " << SDL_GetError() << std::endl;
		initialized = false;
	}
	if (!Renderer::initRenderer(window))
	{
		std::cout << "Renderer create error: " << SDL_GetError() << std::endl;
		initialized = false;
	}
	
	return initialized;
}

void GameWindow::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}
