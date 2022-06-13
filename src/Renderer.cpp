#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Renderer.h"

TTF_Font* Renderer::textFont;
SDL_Color Renderer::textColor;
SDL_Renderer* Renderer::renderer;

bool Renderer::initRenderer(SDL_Window* window)
{
	Renderer::renderer = SDL_CreateRenderer(window, - 1 , SDL_RENDERER_ACCELERATED);
	textFont = TTF_OpenFont("src/res/font.ttf", 24);
	textColor = { 58, 50, 168 , 0 };

	return renderer;
}

SDL_Texture* Renderer::loadTexture(const char* filePath)
{
	SDL_Surface* surface = IMG_Load(filePath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (!texture || !surface)
		std::cout << filePath << " texture is not found!" << std::endl;
	SDL_FreeSurface(surface);

	return texture;
}

void Renderer::renderText(std::string text, int x, int y)
{
	SDL_Surface* textSurface = TTF_RenderText_Solid(textFont, text.c_str(), textColor);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

	int w;
	int h;

	TTF_SizeText(textFont, text.c_str(), &w, &h);

	SDL_Rect textLocation;
	textLocation.x = x;
	textLocation.y = y;
	textLocation.w = w;
	textLocation.h = h;

	SDL_RenderCopy(renderer, textTexture, NULL, &textLocation);

	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);
}

void Renderer::renderTexture(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect)
{
	SDL_RenderCopy(renderer, texture, srcRect, destRect);
}

void Renderer::renderRect(SDL_Rect* destRect)
{
	SDL_RenderFillRect(renderer, destRect);
}

void Renderer::clear()
{
	SDL_RenderClear(renderer);
}

void Renderer::resetColor()
{
    Renderer::setDrawColor(113, 220, 235, 225);
}

void Renderer::draw()
{
	SDL_RenderPresent(renderer);
}

void Renderer::setDrawColor(int r, int g, int b, int a)
{
	SDL_SetRenderDrawColor(renderer, r,g,b,a);
}
