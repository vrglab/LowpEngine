#include "pch.h"
#include "EventHandler.h"

template<typename T>
void EventHandler<T>::Dispatch()
{
    for (const event_function* listener : listeners) {
        listener(static_cast<T&>(m_Event));
    }
}

template<typename T>
void EventHandler<T>::AddListener(const event_function& e)
{
	if(m_Event.GetEventType() == T::GetStaticType())
	{
		listeners.push_back(e);
	}
}
