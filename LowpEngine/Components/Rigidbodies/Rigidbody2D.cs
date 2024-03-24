using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LowpEngine.Components
{
    public sealed class Rigidbody2D : LowpBehaviour
    {
        IntPtr obj_body;
        IntPtr dMass;

        internal IntPtr GetBody()
        {
            return obj_body;
        }

        protected void Start()
        {
            obj_body = RigidbodyUtils.create_body_ode();
            dMass = RigidbodyUtils.create_mass_ode(GetBody());
        }

        void Destroy()
        {
            RigidbodyUtils.destroy_body_ode(GetBody());
        }
    }
}
