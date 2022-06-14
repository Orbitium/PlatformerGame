#pragma once

#include <SDL_rect.h>

class Gravity
{
public:
    Gravity(SDL_Rect* rect)
    {
        this->rect = rect;
    }

    Gravity(SDL_Rect* rect, int fallSpeed)
    {
        this->rect = rect;
        this->fallSpeed = fallSpeed;
    }

protected:
    void fall()
    {
        rect->y = rect->y + fallSpeed;
    }

    float fallSpeed = 1;
private:
    SDL_Rect* rect;
};