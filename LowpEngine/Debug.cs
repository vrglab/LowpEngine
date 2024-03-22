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

        /// <summary>
        /// Log's anything given to it as information to the debug console
        /// </summary>
        /// <param name="msg">The Message to log</param>
        /// <b>Authors</b>
        /// <br>Arad Bozorgmehr (Vrglab)</br>
        public static void Log(object msg)
        {
            _Log(msg.ToString());
        }

        /// <summary>
        /// Log's anything given to it as error to the debug console
        /// </summary>
        /// <param name="msg">The Message to log</param>
        /// <b>Authors</b>
        /// <br>Arad Bozorgmehr (Vrglab)</br>
        public static void LogError(object msg)
        {
            _ErrLog(msg.ToString());
        }

        /// <summary>
        /// Log's anything given to it as warning to the debug console
        /// </summary>
        /// <param name="msg">The Message to log</param>
        /// <b>Authors</b>
        /// <br>Arad Bozorgmehr (Vrglab)</br>
        public static void LogWarning(object msg)
        {
            _WarnLog(msg.ToString());
        }
    }
}
