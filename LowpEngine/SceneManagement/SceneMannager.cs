using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace LowpEngine.SceneManagement
{
    public static class SceneMannager
    {
        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr GetCurrentScene();
    }
}
