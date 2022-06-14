#include "objects/ObjectManager.h"
#include "objects/BasicGameObject.h"
#include "objects/GameObject.h"

int ObjectManager::lastAssignedID = 0;
std::vector<std::unordered_map<int, BasicGameObject*>> ObjectManager::objects;
std::vector<BasicGameObject*> ObjectManager::deleteQueue;

void ObjectManager::initObjects()
{
}

void ObjectManager::deleteObject(int priority, int objectID)
{
    for (std::pair<int, BasicGameObject*> element : objects.at(priority))
    {
        std::cout << element.first << std::endl;
        if (element.first == objectID)
        {
            objects.at(priority).erase(element.first);
            deleteQueue.push_back(element.second);
            std::cout << "Object added to queue!" << std::endl;
            break;
        }
    }
}

void ObjectManager::clearObjects()
{
    for (BasicGameObject* gameObject : deleteQueue)
    {
        delete gameObject;
    }
    deleteQueue.clear();
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