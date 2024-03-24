using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace LowpEngine
{
    /// <summary>
    /// Engine Objects which hold various components within the scene
    /// </summary>
    public class GameObject
    {
        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr InstantiateGameObject(bool sharp, IntPtr obj);

        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr GetGameOBJName(IntPtr instance);

        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void SetGameOBJName(IntPtr instance, string name);

        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr GetGameOBJId(IntPtr instance);

        [DllImport("CoreBindings.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void AddComponentToObj(IntPtr instance, string id);

        /// <summary>
        /// The GameObject's active name
        /// </summary>
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

        public string ID
        {
            get
            {
                if(string.IsNullOrEmpty(id))
                {
                    IntPtr ptr = GetGameOBJId(instance_pointer);
                    id = Marshal.PtrToStringAnsi(ptr);
                }
                return id;
            }
        }

        private string id;
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

        internal GameObject(bool instantiate = true)
        {
            if (instantiate)
            {
                GCHandle handle = GCHandle.Alloc(this, GCHandleType.Pinned);
                IntPtr ptr = GCHandle.ToIntPtr(handle);
                Debug.Log("this is called");
                instance_pointer = InstantiateGameObject(false, ptr);
            }
        }

        internal GameObject()
        {
            
        }

        /// <summary>
        /// Creates a new GameObject within the current scene
        /// </summary>
        /// <returns>The created game object</returns>
        /// <b>Authors</b>
        /// <br>Arad Bozorgmehr (Vrglab)</br>
        public static GameObject Instantiate()
        {
            GameObject obj = new GameObject();
            GCHandle handle = GCHandle.Alloc(obj, GCHandleType.Pinned);
            IntPtr ptr = GCHandle.ToIntPtr(handle);
            obj.instance_pointer = InstantiateGameObject(false, ptr);
            return obj;
        }

        public void AddComponent<t>() where t : LowpBehaviour
        {
            Type type = typeof(t);
            AddComponentToObj(instance_pointer, type.Name);
        }
    }
}
