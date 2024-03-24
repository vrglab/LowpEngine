/* ======================================================================================== */
/* LowpEngine - Event Engine C/C++ header file.												*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include "EventHandler.h"

/**
 * @brief The main class in charge of event handling at runtime within the application space
 */
class EventBus
{
public:
	/**
	 * @brief Que's a given event to be executed on the next event invoke call
	 * @param event_handler The event to que
	 */
	void QueHandler(Ref<EventHandler> event_handler);

	/**
	 * @brief Invokes all of the qued events and then empties it to be ready for the next batch of qued events
	 */
	void ResolveQue();
private:
	std::vector<Ref<EventHandler>> qued_handlers;
};