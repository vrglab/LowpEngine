/* ======================================================================================== */
/* LowpEngine - CoreBindings C/C++ header file.												*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>
#include <SceneEngine/SceneManager.h>

LP_Extern LP_BINDINGS_API inline char* GetGameOBJName(GameObjectInstance*);
LP_Extern LP_BINDINGS_API inline void SetGameOBJName(GameObjectInstance*, char*);
