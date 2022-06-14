#pragma once
#include "HitboxManager.h"

class GameObject;

class Hitbox 
{
protected:
    enum HitboxType
    {
        GROUND,
        ACTIVE_ITEM
    } hitboxes;
public:
    enum HitDirection
    {
        LEFT,
        RIGHT,
        UP,
        BELOW
    } directions;
    
    Hitbox(GameObject* gameObject, bool isActive, HitboxType hitboxType)
    {
        t = gameObject;
        this->isActive = isActive;
        HitboxManager::addNewObject(this);
        this->hitboxType = hitboxType;
    }

    GameObject* t;
    bool isActive;
    HitboxType hitboxType;
    bool isHitted = false;

    virtual void onHit(Hitbox* otherObject, HitDirection xdir, HitDirection ydir) {}

    ~Hitbox()
    {
        HitboxManager::removeObject(this);
    }
};