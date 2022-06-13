#pragma once
#include <SDL_events.h>

#include "EventHandler.h"

class Event
{
public:
    Event()
    {
        EventHandler::registerEvent(this);
    }
    virtual void onEvent(SDL_Event* event) {}
};