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
        GameObject obj = GameObject.Instatiate();
        obj.Name = "Fallout boy is fun";
        Debug.Log($"Obj named {gameObject.Name} made a new GameObject with the id of {obj.ID}");
    }
}
