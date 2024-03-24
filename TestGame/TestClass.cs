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
        AssetsLoader.GetRawAssetContent("bbs");
        obj = GameObject.Instantiate();
        obj.AddComponent<Rigidbody3D>();
    }
}
