#include "pch.h"
#include "EventHandler.h"

template<typename T>
EventHandler<T>::EventHandler(Event& event)
    : m_Event(event) {
    listeners = std::vector<std::function<void(T&)>>();
}

template<typename T>
void EventHandler<T>::Dispatch() {
    for (const auto& listener : listeners) {
        listener(static_cast<T&>(m_Event));
    }
}

template<typename T>
void EventHandler<T>::AddListener(const std::function<void(T&)>& e) {
    if (m_Event.GetEventType() == T::GetStaticType()) {
        listeners.push_back(e);
    }
}
