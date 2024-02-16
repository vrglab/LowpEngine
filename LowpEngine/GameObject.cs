using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace LowpEngine
{
    public class GameObject
    {
        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr InstantiateGameObject(bool sharp);

        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern string GetGameOBJName(IntPtr instance);

        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void SetGameOBJName(IntPtr instance, string name);


        private IntPtr instance_pointer;

        private GameObject(IntPtr instance)
        {
            instance_pointer = instance;
        }

        public GameObject(string name)
        {
            instance_pointer = InstantiateGameObject(false);
            SetGameOBJName(instance_pointer, name);
        }

        public GameObject()
        {
            instance_pointer = InstantiateGameObject(false);
        }

        public static GameObject Instatiate()
        {
            return new GameObject(InstantiateGameObject(false));
        }
    }
}
