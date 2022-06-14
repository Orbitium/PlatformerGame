#pragma once
#include <vector>
#include <unordered_map>

class BasicGameObject;

class ObjectManager
{
public:
    template<typename T, typename... TArgs> static int createObject(int priority, TArgs... args)
    {
        T* t = new T(lastAssignedID, args...);
        if (priority >= objects.size())
        {
            std::unordered_map<int, BasicGameObject*> layer;
            layer.insert({lastAssignedID, t});
            objects.push_back(layer);
        }
        else {
            objects.at(priority).insert({lastAssignedID, t});
        }
        return lastAssignedID++;
    } //Create object and return object's id
    
    static void deleteObject(int priority, int objectID);
    void clearObjects(); //Like garbage collection
    template<typename T> T* getObject(int priority, int objectID);

    void proccessObjects();
    void initObjects(); //For test some object or start some object manually
private:
    static std::vector<std::unordered_map<int , BasicGameObject*>> objects;
    static std::vector<BasicGameObject*> deleteQueue;
    static int lastAssignedID;
};