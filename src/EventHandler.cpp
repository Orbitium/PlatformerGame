#include "EventHandler.h"
#include "GameWindow.h"
#include "Event.h"

std::unordered_set<Event*> EventHandler::handlers;

void EventHandler::handleEvents()
{
	SDL_PollEvent(&event);

    for (Event* eventHandler : handlers)
    {
        eventHandler->onEvent(&event);
    }

	switch (event.type)
	{
	case SDL_QUIT:
		GameWindow::isRunning = false;
		break;
	default:
		break;
	}
}

void EventHandler::registerEvent(Event* event)
{
    handlers.insert(event);
}

void EventHandler::unregisterEvent(Event* event)
{
    handlers.erase(event);
	std::cout << "Handler size: " << handlers.size() << std::endl;
}