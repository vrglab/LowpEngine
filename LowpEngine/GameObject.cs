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
        private static extern IntPtr InstantiateGameObject(bool sharp, IntPtr obj);

        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr GetGameOBJName(IntPtr instance);

        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void SetGameOBJName(IntPtr instance, string name);


        public string Name
        {
            get
            {
                IntPtr ptr = GetGameOBJName(instance_pointer);
                string result = Marshal.PtrToStringAnsi(ptr);
                return result;
            }
            set
            {
                SetGameOBJName(instance_pointer, value);
            }
        }


        private IntPtr instance_pointer;


        private GameObject(IntPtr instance)
        {
            instance_pointer = instance;
        }

        public GameObject(string name)
        {
            GCHandle handle = GCHandle.Alloc(this, GCHandleType.Pinned);
            IntPtr ptr = GCHandle.ToIntPtr(handle);
            instance_pointer = InstantiateGameObject(false, ptr);
            SetGameOBJName(instance_pointer, name);
        }

        public GameObject(bool instantiate = true)
        {
            if (instantiate)
            {
                GCHandle handle = GCHandle.Alloc(this, GCHandleType.Pinned);
                IntPtr ptr = GCHandle.ToIntPtr(handle);
                instance_pointer = InstantiateGameObject(false, ptr);
            }
        }

        public GameObject()
        {
            
        }

        public static GameObject Instatiate()
        {
            GameObject obj = new GameObject();
            GCHandle handle = GCHandle.Alloc(obj, GCHandleType.Pinned);
            IntPtr ptr = GCHandle.ToIntPtr(handle);
            obj.instance_pointer = InstantiateGameObject(false, ptr);
            return obj;
        }
    }
}
