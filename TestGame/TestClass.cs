using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LowpEngine;

public class TestClass : LowpBehaviour
{
    public void Start()
    {
        gameObject.Name = "Test";
        Debug.Log($"Obj name:{gameObject.Name}");
    }
}
