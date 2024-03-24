using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace LowpEngine.SceneManagement
{
    public sealed class SceneMannager
    {
        /// <summary>
        /// Get's the currently open scene
        /// </summary>
        /// <returns>the pointer to the scene</returns>
        /// <b>Authors</b>
        /// <br>Arad Bozorgmehr (Vrglab)</br>
        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr GetCurrentScene();
    }
}
