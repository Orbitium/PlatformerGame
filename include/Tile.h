#pragma once
#include <SDL.h>

#include "GameObject.h"

class Tile
{
public:
    Tile(int x, int y, int id)
    {

    }

private:
    SDL_Rect srcRect, destRect;
};