#pragma once
#include "GameObject.h"
#include "../Event.h"
#include "../Hitbox.h"
#include "Gravity.h"

class Player : public GameObject , Event, Hitbox, Gravity
{
private:
    int speed = 10;
    int health = 5;
    int xAcceleration = 0; 
    float yAcceleration = 0; 
    bool onGround = false;
public:
    Player(int uniqueID, int x, int y) : GameObject(uniqueID, "res/box.png", x, y) , Event() , Hitbox(this, true, HitboxType::GROUND), Gravity(&destRect) {}
    void onEvent(SDL_Event* event) override;
    void onHit(Hitbox* otherObject, HitDirection xdir, HitDirection ydir) override;
    void update() override;
};