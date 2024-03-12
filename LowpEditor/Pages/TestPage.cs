using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LowpEngine;

namespace LowpEditor.Pages
{
    public class TestPage : EditorWindow
    {
       void Start()
       {
            Debug.Log("Tesy");
       }

       void ImGuiRender()
       {
           ImGui.WriteText("This is a test text");
       }
    }
}
