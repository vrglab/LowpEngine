#include "pch.h"
#include "EventHandler.h"


EventHandler::EventHandler() {
    listeners = std::vector<std::function<void()>>();
}


void EventHandler::Dispatch() {
    for (const auto& listener : listeners) {
        listener();
    }
}

void EventHandler::AddListener(const std::function<void()>& e) {
    listeners.push_back(e);
}
