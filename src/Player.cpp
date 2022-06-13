#include "objects/Player.h"

void Player::onEvent(SDL_Event* event)
{
    if (event->type == SDL_KEYDOWN) {
        switch(event->key.keysym.sym)
        {
            case SDLK_a:
                xAcceleration = -speed;
                break;
            case SDLK_d:
                xAcceleration = speed;
                break;
        }
    }
    else if (event->type == SDL_KEYUP) {
        switch(event->key.keysym.sym)
        {
            case SDLK_a:
            if (xAcceleration < 0)
                xAcceleration = 0;
                break;
            case SDLK_d:
            if (xAcceleration > 0)
                xAcceleration = 0;
                break;
        }
    }
}

void Player::update()
{
    setX(getX() + xAcceleration);
    setY(getY() + yAcceleration);
}