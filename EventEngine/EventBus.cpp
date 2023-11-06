#include "pch.h"
#include "EventBus.h"


void EventBus::QueHandler(void* event_handler)
{
	qued_handlers.push_back(event_handler);
}

void EventBus::ResolveQue()
{
	for (void* handler : qued_handlers) {
		((EventHandlerBase*)handler)->Dispatch();
	}
	qued_handlers.clear();
}
