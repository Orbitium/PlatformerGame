#pragma once
#include <unordered_set>

class Hitbox;

class HitboxManager
{
public:
    static void addNewObject(Hitbox* hitbox);
    static void removeObject(Hitbox* hitbox);

    void checkCollisions();
private:
    static std::unordered_set<Hitbox*> inactiveObjects; //Like ground
    static std::unordered_set<Hitbox*> activeObjects; //Like player, arrow, enemies
};