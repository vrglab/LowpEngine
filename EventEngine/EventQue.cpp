#include "pch.h"
#include "EventQue.h"

void EventQue::Enqueue(Ref<Event> event)
{
	m_EventQueue.push_back(event);
}

void EventQue::AddListener(int eventType, const std::function<void(Ref<Event>)>& listener)
{
	eventListeners_[eventType].push_back(listener);
}

void EventQue::DispatchEvents()
{
    for (Ref<Event> event : m_EventQueue) {
        int eventType = event->GetEventType();
        if (eventListeners_.count(eventType)) {
            for (const auto& listener : eventListeners_[eventType]) {
                listener(event);
            }
        }
    }
}
