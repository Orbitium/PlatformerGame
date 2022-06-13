#pragma once
#include <SDL.h>
#include <iostream>

#include "GameWindow.h"
#include "BasicGameObject.h"
#include "Renderer.h"

class GameObject : public BasicGameObject
{
public:
	GameObject(int uniqueID, const char* texturePath, int x, int y) : BasicGameObject(uniqueID, x, y)
	{
		texture = Renderer::loadTexture(texturePath);

		srcRect.x = srcRect.y = 0;
		destRect.h = destRect.w = srcRect.w = srcRect.h = 50;

		destRect.x = x;
		destRect.y = y;
		std::cout << "GameObject created!" << std::endl;
	}

	GameObject(int uniqueID, const char* texturePath, int x, int y, int w, int h) : BasicGameObject(uniqueID,x,y,w,h)
	{
		texture = Renderer::loadTexture(texturePath);

		srcRect.x = srcRect.y = 0;
		srcRect.w = destRect.w = w;
		srcRect.h = destRect.h = h;

		destRect.x = x;
		destRect.y = y;
	}
	
	GameObject(int uniqueID, const char* texturePath, int x, int y, int w, int h, int s_x, int s_y) : BasicGameObject(uniqueID,x,y,w,h)
	{
		texture = Renderer::loadTexture(texturePath);

		srcRect.x = s_x;
		srcRect.y = s_y;
		srcRect.w = destRect.w = w;
		srcRect.h = destRect.h = h;

		destRect.x = x;
		destRect.y = y;
	}

	void setTexture(SDL_Texture* texture) { this->texture = texture; }

	void render() override { //render was came from BasicGameObject.h
		Renderer::renderTexture(texture, &srcRect, &destRect);
	}

	int getSX() {return srcRect.x;}
	int getSY() {return srcRect.y;}

	void setSX(int newX) {srcRect.x = newX;}
	void setSY(int newY) {srcRect.y = newY;}

	SDL_Rect& getDestRect() {return destRect;}
	int& getID() {return uniqueID;}

private:
	int uniqueID;
	SDL_Texture* texture;
	SDL_Rect /*destRect*/ srcRect; //destRect was came from BasicGameObject.h
};