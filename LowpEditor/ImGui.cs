using LowpEngine;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace LowpEditor
{
    public class ImGui
    {
        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void imgui_text(string txt);
    
        public static void WriteText(string txt)
        {
            imgui_text(txt);
        }
    }
}
