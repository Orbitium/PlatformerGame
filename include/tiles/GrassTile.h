#pragma once

#include "Hitbox.h"
#include "../objects/GameObject.h"

class GrassTile : public GameObject, Hitbox
{
public:
    GrassTile(int uniqueID, const char* texturePath, int x, int y) : GameObject(uniqueID, texturePath, x, y) ,
    Hitbox(this, false, HitboxType::GROUND) {}

};