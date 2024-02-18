using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LowpEngine;
using LowpEngine.AssetsHandeling;

public class TestClass : LowpBehaviour
{
    public void Start()
    {
        gameObject.Name = "Test"; 
        Debug.Log($"Obj name is {gameObject.Name} and it says: {AssetsLoader.GetRawAssetContent("Test.txt")}");
    }
}
