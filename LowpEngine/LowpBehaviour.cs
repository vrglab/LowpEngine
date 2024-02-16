using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace LowpEngine
{
    public abstract class LowpBehaviour
    {
        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr InstantiateGameObject();

        public static void Instatiate()
        {
            InstantiateGameObject();
        }
    }
}
