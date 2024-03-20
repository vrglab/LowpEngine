/* ======================================================================================== */
/* LowpEngine - CoreBindings C/C++ header file.												*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include "CustomMacros.h"
#include <PhysicsEngine/PhysicsEngine.h>
#include "SceneBindings.h"

LP_Extern LP_BINDINGS_API inline dBodyID create_body_ode();
LP_Extern LP_BINDINGS_API inline dMass* create_mass_ode(dBodyID);
LP_Extern LP_BINDINGS_API inline void destroy_body_ode(dBodyID);
