# LowpEngine
C++/C# based Game Engine, fully free and open source.
 
## list of Projects

1. Core (C++): This is the core engine.
1. PhysicsEngine (C++): The Physics engine, uses both ODE and Box2D to handle diffrent Physics contexts
1. RenderingEngine (C++): Our own cross-platform Rendering Engine 
1. SoundEngine (C++): The Engine in charge of handling audio systems (Multibackend: OpenAL, Fmod ...)
1. ScriptingEngine (C++): The main engine handeling C# scripting
1. EngineCommons (C++): All of the code shared between diffrent (C++) projects.
9. Launcher(C++): The main launcher. (the executable to launch the game basically)
9. AassetsEngine(C++): The main engine in charge of asset controll
9. EventEngine(C++): Our own multi-purpose event system
9. SceneEngine(C++): The engine in charge of loading pre-defined scenes (states) (This engine contain things such as: Object and component instancing, prefabs ...)
9. LowpEngine(C#): This is our C# Api all games made with the engine will have to drive from this api to comunicate/use engine based features

# Building/IDE Envoirment Generation
Clone the project using `git clone git@github.com:vrglab/LowpEngine.git` and Run the `Generate` this should generate the default IDE envoirment

### Windows
On windows running the `Generate.bat` file should by default create `Visual Studio Comunity 2022` project files and using Visual Studio you should be able to just build the project.

### Linux
On linux running the `Generate.sh` file in the console using `sh`,should by default create `Gmake2` files and by running the `make` command in the bash with a `config=` of your chosing (you can see the configs by opening the generated Makefile), you should be able to build the project

# Currently Supported features
This are all of the feature that are already fully or partially implemented into the Project
1. Cross-Platform Rendering (OpenGl, Vulkan, DirectX12, Metal.)
1. Asset Controll.
1. Game object/Component system.
1. Scene Management
1. Engine Customization.
1. Built in Audio system (OpenAL, Fmod, Wwise).

# Planned to Support
this are all feature i plan on supporting (that i can remember right now)
1. Bash based executables.
1. Customizable Asset importer.
1. 2D/3D.
1. 3D model loading.
1. Physics 2D/3D.
1. Particles.
2. Indexed Rendering.
3. Mesh batching.
4. Builtin base components.
4. Multiplatform building (Consoles, Phones, Computers).
