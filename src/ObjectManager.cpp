#include "objects/ObjectManager.h"
#include "objects/BasicGameObject.h"
#include "objects/GameObject.h"

int ObjectManager::lastAssignedID = 0;
std::vector<std::unordered_map<int, BasicGameObject*>> ObjectManager::objects;

void ObjectManager::initObjects()
{
}

void ObjectManager::deleteObject(int priority, int objectID)
{
    for (std::pair<int, BasicGameObject*> element : objects.at(priority))
    {
        if (element.first == objectID)
        {
            objects.at(priority).erase(element.first);
            delete element.second;
            break;
        }
    }
}

template<typename T> T* ObjectManager::getObject(int priority, int objectID) //Probably not working
{
    return static_cast<T*>(objects.at(priority).at(objectID));
}

void ObjectManager::proccessObjects()
{
    std::vector<std::unordered_map<int , BasicGameObject*>>::iterator mapIterator;
    
    for (mapIterator = objects.begin(); mapIterator < objects.end(); mapIterator++)
    {
        std::unordered_map<int, BasicGameObject*>::iterator objectIterator = mapIterator->begin();
        while(objectIterator != mapIterator->end())
        {
            objectIterator->second->update();
            objectIterator->second->render();
            objectIterator++;
        }
    }
}