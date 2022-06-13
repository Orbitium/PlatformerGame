#pragma once
#include <unordered_set>
#include <SDL_events.h>

class Event;

class EventHandler
{
public:
    void handleEvents();
    static void registerEvent(Event* event);
    static void unregisterEvent(Event* event);
private:
    static std::unordered_set<Event*> handlers;
    SDL_Event event;
};