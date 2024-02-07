using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;

namespace LowpEngine
{
    public class LowpBehaviour
    {
        [DllImport("CoreBindings.lib")]
        private static extern void Log(string msg);
    }
}
