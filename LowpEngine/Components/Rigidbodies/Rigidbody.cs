using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace LowpEngine.Components
{
    public class Rigidbody : LowpBehaviour
    {
        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr create_body_ode();

        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr destroy_body_ode(IntPtr body);

        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr create_mass_ode(IntPtr body);


        IntPtr obj_body;
        IntPtr dMass;

        protected void Start()
        {
            obj_body = create_body_ode();
            dMass = create_mass_ode(obj_body);
        }

        internal IntPtr GetBody()
        {
            return obj_body;
        }

        void Destroy()
        {
            destroy_body_ode(obj_body);
        }
    }
}
