#include "pch.h"
#include "PhysicsBindings.h"

LP_Extern LP_BINDINGS_API dBodyID create_body_ode()
{
    return dBodyCreate((dWorldID)SceneManager::GetCurrentScene()->configs.GetConfig("phys_world"));
}

LP_Extern LP_BINDINGS_API dMass create_mass_ode(dBodyID body)
{
    dMass m;
    dMassSetZero(&m);
    dBodySetMass(body, &m);
    return m;
}

LP_Extern LP_BINDINGS_API void destroy_body_ode(dBodyID body)
{
    dBodyDestroy(body);
}
