#include "pch.h"
#include "EventBus.h"

template<typename T>
void EventBus::QueHandler(Ref<EventHandler<T>> event_handler)
{
	qued_handlers.push_back(event_handler);
}

void EventBus::ResolveQue()
{
	for (Ref<EventHandlerBase> handler : qued_handlers) {
		handler->Dispatch();
	}
	qued_handlers.clear();
}
