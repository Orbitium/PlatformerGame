#pragma once
#include <vector>
#include <unordered_set>
#include <unordered_map>

#include "objects/BasicGameObject.h"
#include <iostream>

class ObjectManager
{
public:
    template<typename T, typename... TArgs> static std::uint16_t createObject(std::uint16_t priority, TArgs... args)
    {
        T* t = new T(lastAssignedID, args...);
        if (priority >= objects.size())
        {
            std::unordered_map<std::uint16_t, BasicGameObject*> layer;
            layer.insert({lastAssignedID, t});
            objects.push_back(layer);
        }
        else {
            objects.at(priority).insert({lastAssignedID, t});
        }
        return lastAssignedID++;
    } //Create object and return object's id
    
    static void deleteObject(std::uint16_t priority, std::uint16_t objectID); //Add object to objectClearQueue
    template<typename T> T* getObject(std::uint16_t priority, std::uint16_t objectID);

    void clearObject(); //Like garbage collection, delete all object after rendering & updating
    void proccessObjects();

    void initObjects(); //For test some object or start some object manually
private:
    static std::vector<std::unordered_map<std::uint16_t , BasicGameObject*>> objects;
    static std::uint16_t lastAssignedID;
};