using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;

namespace LowpEngine
{
    public sealed class Debug
    {
        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void _Log(string msg);

        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void _ErrLog(string msg);

        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void _WarnLog(string msg);

        public static void Log(string msg)
        {
            _Log(msg);
        }

        public static void LogError(string msg)
        {
            _ErrLog(msg);
        }

        public static void LogWarning(string msg)
        {
            _WarnLog(msg);
        }
    }
}
