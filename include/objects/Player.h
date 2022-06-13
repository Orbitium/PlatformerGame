#pragma once
#include "GameObject.h"
#include "../Event.h"

class Player : public GameObject , Event
{
private:
    int speed = 10;
    int health = 5;
    int xAcceleration = 0; 
    int yAcceleration = 0; 
public:
    Player(int uniqueID, int x, int y) : GameObject(uniqueID, "res/box.png", x, y) , Event() {}
    void onEvent(SDL_Event* event) override;
    void update() override;
};