#include "pch.h"
#include "EventBus.h"


void EventBus::QueHandler(Ref<EventHandler> event_handler)
{
	qued_handlers.push_back(event_handler);
}

void EventBus::ResolveQue()
{
	for (Ref<EventHandler> handler : qued_handlers) {
		handler->Dispatch();
	}
	qued_handlers.clear();
}
