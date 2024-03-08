using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LowpEngine;
using LowpEngine.AssetsHandeling;
using LowpEngine.Components;

public class TestClass : LowpBehaviour
{

    GameObject obj;
    public void Start()
    {
        Debug.Log($"Obj start");
        obj = GameObject.Instatiate();
        obj.AddComponent<Rigidbody3D>();
    }

    public void Update()
    {
       
    }
}
