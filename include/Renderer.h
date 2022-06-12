#pragma once
#include <SDL.h>
#include <SDL_TTF.h>
#include <string>

class GameObject;

class Renderer {
public:
	void clear();
	void draw();

	static SDL_Texture* loadTexture(const char* filePath);
	static void renderTexture(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect);
	static void renderRect(SDL_Rect* destRect);
	static void renderText(std::string text, int x, int y);

	static bool initRenderer(SDL_Window* window);

	static void setDrawColor(int r, int g, int b, int a);
	void resetColor();
	//static void fillRect(SDL_Rect* rect);
private:
	static TTF_Font* textFont;
	static SDL_Color textColor;
	static SDL_Renderer* renderer;
};