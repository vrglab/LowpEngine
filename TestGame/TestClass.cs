using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LowpEngine;
using LowpEngine.AssetsHandeling;

public class TestClass : LowpBehaviour
{

    GameObject obj;
    public void Start()
    {
        Debug.Log($"Obj start");
    }

    public void Update()
    {
        Debug.Log($"Obj update");
    }
}
