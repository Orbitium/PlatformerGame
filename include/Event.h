#pragma once
#include <SDL_events.h>
#include <iostream>

#include "EventHandler.h"

class Event
{
public:
    Event()
    {
        EventHandler::registerEvent(this);
    }

    ~Event()
    {
        EventHandler::unregisterEvent(this);
        std::cout << "Event destuctor called! " << std::endl;
    }
    
    virtual void onEvent(SDL_Event* event) {}
};