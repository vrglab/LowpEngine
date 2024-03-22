using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace LowpEngine.Components
{
    /// <summary>
    /// Internal Class for Binding C++ physics functions
    /// </summary>
    /// <b>Authors</b>
    /// <br>Arad Bozorgmehr (Vrglab)</br>
    internal class RigidbodyUtils
    {
        /// <summary>
        /// Create a Physics body
        /// </summary>
        /// <returns>pointer to the created body</returns>
        /// <b>Authors</b>
        /// <br>Arad Bozorgmehr (Vrglab)</br>
        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr create_body_ode();

        /// <summary>
        /// Destroys the given body
        /// </summary>
        /// <param name="body">The pointer to the physics body to destroy</param>
        /// <b>Authors</b>
        /// <br>Arad Bozorgmehr (Vrglab)</br>
        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void destroy_body_ode(IntPtr body);

        /// <summary>
        /// Creates a Physics mass for the given body
        /// </summary>
        /// <param name="body">The pointer to the body of the mass</param>
        /// <returns>The pointer to the mass</returns>
        /// <b>Authors</b>
        /// <br>Arad Bozorgmehr (Vrglab)</br>
        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr create_mass_ode(IntPtr body);
    }
}
