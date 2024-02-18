using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace LowpEngine
{
    public abstract class LowpBehaviour
    {
        public GameObject gameObject
        {
            get
            {
                return _gameobj;
            }
        }

        private GameObject _gameobj;
    }
}
