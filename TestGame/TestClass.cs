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
        Debug.Log($"Obj name was {gameObject.Name}");
        gameObject.Name = "Test"; 
        Debug.Log($"Obj name is {gameObject.Name}, it's id is {gameObject.ID} and it says: {AssetsLoader.GetRawAssetContent("Test.txt")}");
        obj = GameObject.Instatiate();
        obj.Name = "Fallout boy is fun";
        Debug.Log($"Obj named {gameObject.Name} made a new GameObject with the id of {obj.ID}");
    }

    public void Update()
    {
        Debug.Log($"Hello from {obj.ID}");
    }
}
