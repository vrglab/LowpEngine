#include "pch.h"
#include "EventHandler.h"

template<typename T>
void EventHandler<T>::Dispatch()
{
    for (const std::function<bool(T&)>* listener : listeners) {
        listener(static_cast<T&>(m_Event));
    }
}

template<typename T>
void EventHandler<T>::AddListener(const std::function<bool(T&)>& e)
{
	if(m_Event.GetEventType() == T::GetStaticType())
	{
		listeners.push_back(e);
	}
}
