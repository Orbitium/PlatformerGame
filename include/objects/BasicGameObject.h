#pragma once
#include <SDL.h>

#include "Renderer.h"

class BasicGameObject //If any game object created in the program MUST include this class
{
public:
    BasicGameObject(std::uint16_t uniqueID, int x, int y, int w, int h)
    {
        this->uniqueID = uniqueID;
        destRect = SDL_Rect{x,y,w,h};
    }
    BasicGameObject(std::uint16_t uniqueID, int x, int y)
    {
        this->uniqueID = uniqueID;
        destRect = SDL_Rect{x,y,50,50};
    }

    int getX(){return destRect.x;}
    int getY(){return destRect.y;}
    int getW(){return destRect.w;}
    int getH(){return destRect.h;}

    void setX(int newX) {destRect.x = newX;}
    void setY(int newY) {destRect.y = newY;}
    void setW(int newW) {destRect.w = newW;}
    void setH(int newH) {destRect.h = newH;}

    virtual void render()
    {
        Renderer::setDrawColor(0,0,0,225);
        Renderer::renderRect(&destRect);
    }

    virtual void update() {}

    int getID() {return uniqueID;}
protected:
    SDL_Rect destRect;
    int uniqueID;
};