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

        /// <summary>
        /// Loads a assets raw file content
        /// </summary>
        /// <param name="hrid">The human readable identifier of the asset</param>
        /// <returns>The found file data</returns>
        /// <b>Authors</b>
        /// <br>Arad Bozorgmehr (Vrglab)</br>
        public static string GetRawAssetContent(string hrid)
        {
            return Marshal.PtrToStringAnsi(GetHRIDFileContent(hrid));
        }
    }
}
