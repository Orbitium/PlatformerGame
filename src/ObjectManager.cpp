#include "objects/ObjectManager.h"
#include "objects/BasicGameObject.h"
#include "objects/GameObject.h"

std::uint16_t ObjectManager::lastAssignedID = 0;
std::vector<std::unordered_map<std::uint16_t, BasicGameObject*>> ObjectManager::objects;

void ObjectManager::initObjects()
{
	createObject<GameObject>(std::uint16_t(0), "res/box.png", 20, 0);
	createObject<BasicGameObject>(std::uint16_t(0), 20, 60);
}

void ObjectManager::deleteObject(std::uint16_t priority, std::uint16_t objectID)
{
    for (std::pair<std::uint16_t, BasicGameObject*> element : objects.at(priority))
    {
        if (element.first == objectID)
        {
            objects.at(priority).erase(element.first);
            delete element.second;
            break;
        }
    }
}

template<typename T> T* ObjectManager::getObject(std::uint16_t priority, std::uint16_t objectID) //Probably not working
{
    return static_cast<T*>(objects.at(priority).at(objectID));
}

void ObjectManager::proccessObjects()
{
    std::vector<std::unordered_map<std::uint16_t , BasicGameObject*>>::iterator mapIterator;
    
    for (mapIterator = objects.begin(); mapIterator < objects.end(); mapIterator++)
    {
        std::unordered_map<std::uint16_t, BasicGameObject*>::iterator objectIterator = mapIterator->begin();
        while(objectIterator != mapIterator->end())
        {
            objectIterator->second->update();
            objectIterator->second->render();
            objectIterator++;
        }
    }
}