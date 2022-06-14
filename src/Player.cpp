#include "objects/Player.h"
#include "objects/ObjectManager.h"

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
            case SDLK_f:
                ObjectManager::deleteObject(2, getID());
                break;
            case SDLK_SPACE:
                if(onGround && yAcceleration == 0)
                    yAcceleration = -15;
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
    if (yAcceleration < -1) {
        setY(getY() + yAcceleration);
        yAcceleration += 0.5;
    }
    else if (yAcceleration == -1)
    {
        fallSpeed = 4;
        setY(getY() + yAcceleration);
        yAcceleration = 0;  
    }
    else if (!onGround) {
        fall();
        fallSpeed += 0.8;
    }
    else if (!isHitted)
        onGround = false;
    std::cout << yAcceleration << std::endl;

}

void Player::onHit(Hitbox* otherObject, HitDirection xdir, HitDirection ydir)
{
    if (otherObject->hitboxType == GROUND && ydir == UP) {
        onGround = true;
        isHitted = false; //Reset hit state
        destRect.y = otherObject->t->getDestRect().y - otherObject->t->getDestRect().h + 1;
    }
}