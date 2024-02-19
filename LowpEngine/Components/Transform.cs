using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LowpEngine
{
    public sealed class Transform : LowpBehaviour
    {
        private float _x, _y, _z;

        public float x { get { return _x; } set { _x = value; } }
        public float y { get { return _x; } set { _x = value; } }
        public float z { get { return _x; } set { _x = value; } }

        void Start()
        {
            
        }
    }
}
