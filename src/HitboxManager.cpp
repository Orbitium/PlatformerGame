#include "HitboxManager.h"
#include "Hitbox.h"
#include "objects/GameObject.h"
#include <iostream>

std::unordered_set<Hitbox*> HitboxManager::inactiveObjects;
std::unordered_set<Hitbox*> HitboxManager::activeObjects;

void HitboxManager::addNewObject(Hitbox* hitbox)
{
    if (hitbox->isActive)
        activeObjects.insert(hitbox);
    else 
        inactiveObjects.insert(hitbox);
}

void HitboxManager::removeObject(Hitbox* hitbox)
{
    if (hitbox->isActive)
        activeObjects.erase(hitbox);
    else 
        inactiveObjects.erase(hitbox);   
}

void HitboxManager::checkCollisions()
{
    for (Hitbox* activeObject : activeObjects)
    {
        for (Hitbox* inactiveObject : inactiveObjects)
        {
            if (SDL_HasIntersection(&activeObject->t->getDestRect(), &inactiveObject->t->getDestRect()))
            {
                Hitbox::HitDirection xdir;
                Hitbox::HitDirection ydir;
                if (activeObject->t->getX() - inactiveObject->t->getX() <= 0)
                    xdir = Hitbox::HitDirection::LEFT;
                else
                    xdir = Hitbox::HitDirection::RIGHT;

                if (activeObject->t->getY() - inactiveObject->t->getY() <= 0)
                    ydir = Hitbox::HitDirection::UP;
                else
                    ydir = Hitbox::HitDirection::BELOW;
                activeObject->isHitted = true;
                activeObject->onHit(inactiveObject, xdir, ydir);
                inactiveObject->onHit(activeObject, xdir, ydir);
            }
        }
    }
    for (auto itr1 = activeObjects.begin(); itr1 != activeObjects.end(); itr1++) {
        for (auto itr2 = itr1; itr2 != activeObjects.end(); itr2++) {
            if (itr1 != itr2)
            if (SDL_HasIntersection(&(*itr1)->t->getDestRect(), &(*itr2)->t->getDestRect()))
            {
                Hitbox::HitDirection xdir;
                Hitbox::HitDirection ydir;
                if ((*itr1)->t->getX() - (*itr2)->t->getX() <= 0)
                    xdir = Hitbox::HitDirection::LEFT;
                else
                    xdir = Hitbox::HitDirection::RIGHT;

                if ((*itr1)->t->getY() - (*itr2)->t->getY() <= 0)
                    ydir = Hitbox::HitDirection::BELOW;
                else
                    ydir = Hitbox::HitDirection::UP;
                (*itr1)->onHit((*itr2), xdir, ydir);
                (*itr2)->onHit((*itr1), xdir, ydir);
            }
        }
    }
}
