using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace LowpEngine.AssetsHandeling
{
    public sealed class AssetsLoader
    {
        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr GetHRIDFileContent(string hrid);

        public static string GetRawAssetContent(string hrid)
        {
            IntPtr intPtr = GetHRIDFileContent(hrid);
            string data = Marshal.PtrToStringAnsi(intPtr);
            return data;
        }
    }
}
