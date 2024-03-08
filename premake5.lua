projects_without_pch = {"STB", "ImGui"}

function determine_os()
    if os.ishost("windows") then
        return "windows"
    elseif os.ishost("linux") then
        return "linux"
    elseif os.ishost("macosx") then
        return "macOS"
    else
        return "Unknown"
    end
end

-- Function to determine the current architecture
function determine_architecture()
    if os.is64bit() then
        return "x64"
    else
        return "x86"
    end
end


workspace "LowpEngine"
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Debug_Game",
		"Release_Game",
		"Debug_Editor",
		"Release_Editor"
	}
	platforms { "x86", "x64", "ARM", "ARM64" }
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	vcpkg_arg_dir = determine_architecture().."-"..determine_os();

	filter "configurations:Debug"
		symbols "On"
		defines {"DEBUG"}
	if  os.target() == "linux" then
		if projects_without_pch["%{prj.name}"] == false then
			prebuildcommands {
				"{MKDIR} %{cfg.targetdir}/pch",
				"g++ ../%{prj.name}/pch.h -o %{cfg.objdir}/pch.h.gch -c -x c++-header -std=c++20"
			}
		end
	end

	filter "configurations:Release"
		optimize "On"
		defines {"RELEASE"}
	if  os.target() == "linux" then
		if projects_without_pch["%{prj.name}"] == false then
			prebuildcommands {
				"{MKDIR} %{cfg.targetdir}/pch",
				"g++ ../%{prj.name}/pch.h -o %{cfg.objdir}/pch.h.gch -c -x c++-header -std=c++20"
			}
		end
	end

	filter "configurations:Debug_Game"
		symbols "On"
		defines {"DEBUG", "GAME"}
	if  os.target() == "linux" then
		if projects_without_pch["%{prj.name}"] == false then
			prebuildcommands {
				"{MKDIR} %{cfg.targetdir}/pch",
				"g++ ../%{prj.name}/pch.h -o %{cfg.objdir}/pch.h.gch -c -x c++-header -std=c++20"
			}
		end
	end

	filter "configurations:Release_Game"
		optimize "On"
		defines {"RELEASE", "GAME"}
	if  os.target() == "linux" then
		if projects_without_pch["%{prj.name}"] == false then
			prebuildcommands {
				"{MKDIR} %{cfg.targetdir}/pch",
				"g++ ../%{prj.name}/pch.h -o %{cfg.objdir}/pch.h.gch -c -x c++-header -std=c++20"
			}
		end
	end

	filter "configurations:Debug_Editor"
		symbols "On"
		defines {"DEBUG", "EDITOR"}
	if  os.target() == "linux" then
		if projects_without_pch["%{prj.name}"] == false then
			prebuildcommands {
				"{MKDIR} %{cfg.targetdir}/pch",
				"g++ ../%{prj.name}/pch.h -o %{cfg.objdir}/pch.h.gch -c -x c++-header -std=c++20"
			}
		end
	end

	filter "configurations:Release_Editor"
		optimize "On"
		defines {"RELEASE", "EDITOR"}
	if  os.target() == "linux" then
		if projects_without_pch["%{prj.name}"] == false then
			prebuildcommands {
				"{MKDIR} %{cfg.targetdir}/pch",
				"g++ ../%{prj.name}/pch.h -o %{cfg.objdir}/pch.h.gch -c -x c++-header -std=c++20"
			}
		end
	end
			
group "C++/Engine"
project "Core"
	location "Core"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		toolset "v143"
		cppdialect "C++latest"
		links 
		{
			"d3d12",
			"dxgi",
			"D3DCompiler"
		}
		libdirs
		{
			"Packages/c++/libs/windows"
		}
		buildoptions
		{
			"/Zc:__cplusplus"
		}
	elseif os.target() == "linux" then
		pchheader "%{prj.name}/pch.h"
	end

	pchsource "%{prj.name}/pch.cpp"

	files 
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**/**.h",
		"%{prj.name}/**/**.cpp"
	}

	libdirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/lib"
	}

	includedirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/include",
		"Packages/c++/includes",
		"%{prj.name}",
		"."
	}

	links
	{
		"AssetsEngine",
		"SoundEngine",
		"PhysicsEngine",
		"RenderingEngine",
		"EngineCommons",
		"ScriptingEngine",
		"EventEngine",
		"SceneEngine",
		"SDL2",
		"spdlog",
		"fmt",
		"volk",
		"mono-2.0-sgen",
		"ode_double"
	}

	vpaths {
		["Headers/*"] = { "**.h", "**.hpp" },
		["Sources/*"] = {"**.c", "**.cpp"}
	}


	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Game"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release_GAME"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Editor"
		defines {"LP_API_EXPORTS"}
		links
		{
			"ImGui"
		}

	filter "configurations:Release_Editor"
		defines {"LP_API_EXPORTS"}
		links
		{
			"ImGui"
		}

project "CoreBindings"
	location "CoreBindings"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		toolset "v143"
		cppdialect "C++latest"
		libdirs
		{
			"Packages/c++/libs/windows"
		}
				buildoptions
		{
			"/Zc:__cplusplus"
		}
	elseif os.target() == "linux" then
		pchheader "%{prj.name}/pch.h"
	end

	pchsource "%{prj.name}/pch.cpp"

	files 
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**/**.h",
		"%{prj.name}/**/**.cpp"
	}

	libdirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/lib"
	}

	includedirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/include",
		"Packages/c++/includes",
		"%{prj.name}",
		"."
	}

	links
	{
		"SceneEngine",
		"PhysicsEngine",
		"AssetsEngine",
		"Core",
		"SDL2",
		"spdlog",
		"fmt",
		"volk",
		"mono-2.0-sgen",
		"ode_double"
	}

	vpaths {
		["Headers/*"] = { "**.h", "**.hpp" },
		["Sources/*"] = {"**.c", "**.cpp"}
	}


	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines {"LP_BINDINGS_API_EXPORTS"}

	filter "configurations:Release"
		defines {"LP_BINDINGS_API_EXPORTS"}
	
	filter "configurations:Debug_Game"
		defines {"LP_BINDINGS_API_EXPORTS"}

	filter "configurations:Release_GAME"
		defines {"LP_BINDINGS_API_EXPORTS"}

	filter "configurations:Debug_Editor"
		defines {"LP_BINDINGS_API_EXPORTS"}

	filter "configurations:Release_Editor"
		defines {"LP_BINDINGS_API_EXPORTS"}

project "EngineCommons"
	location "EngineCommons"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		toolset "v143"
		pchheader "pch.h"
		cppdialect "C++latest"
		buildoptions
		{
			"/Zc:__cplusplus"
		}
	elseif os.target() == "linux" then
		pchheader "%{prj.name}/pch.h"
	end

	pchsource "%{prj.name}/pch.cpp"

	files 
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**/**.h",
		"%{prj.name}/**/**.cpp"
	}

	libdirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/lib"
	}

	includedirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/include",
		"Packages/c++/includes",
		"%{prj.name}",
		"."
	}

	links
	{
		"zlib"
	}

	vpaths {
		["Headers/*"] = { "**.h", "**.hpp" },
		["Sources/*"] = {"**.c", "**.cpp"}
	}


	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Game"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release_GAME"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Editor"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release_Editor"
		defines {"LP_API_EXPORTS"}

project "Launcher"
	location "Launcher"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")



	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
		toolset "v143"
		libdirs
		{
			"Packages/c++/libs/windows"
		}
		buildoptions
		{
			"/Zc:__cplusplus"
		}
	elseif os.target() == "linux" then
		pchheader "%{prj.name}/pch.h"
	end

	pchsource "%{prj.name}/pch.cpp"

	files 
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**/**.h",
		"%{prj.name}/**/**.cpp"
	}

	libdirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/lib"
	}

	includedirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/include",
		"Packages/c++/includes",
		"%{prj.name}",
		"."
	}
	
	links
	{
		"Core",
		"SDL2",
		"spdlog",
		"fmt",
		"volk",
		"mono-2.0-sgen"
	}

	vpaths {
		["Headers/*"] = { "**.h", "**.hpp" },
		["Sources/*"] = {"**.c", "**.cpp"}
	}


	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

-- C++ Subsystems that are used in the engine
group "C++/Engine/SubEngines"
project "SoundEngine"
	location "SoundEngine"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
		toolset "v143"
		libdirs
		{
			"Packages/c++/libs/windows"
		}
		buildoptions
		{
			"/Zc:__cplusplus"
		}
	elseif os.target() == "linux" then
		pchheader "%{prj.name}/pch.h"
	end

	pchsource "%{prj.name}/pch.cpp"

	files 
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**/**.h",
		"%{prj.name}/**/**.cpp"
	}

	libdirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/lib"
	}

	includedirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/include",
		"%{prj.name}",
		"Packages/c++/includes",
		"."
	}
	
	links
	{
		"STB",
		"OpenAL32",
		"fmod",
		"fmodstudio",
		"EngineCommons"
	}

	vpaths {
		["Headers/*"] = { "**.h", "**.hpp" },
		["Sources/*"] = {"**.c", "**.cpp"}
	}


	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Game"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release_GAME"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Editor"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release_Editor"
		defines {"LP_API_EXPORTS"}

project "PhysicsEngine"
	location "PhysicsEngine"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
		toolset "v143"
		buildoptions
		{
			"/Zc:__cplusplus"
		}
	elseif os.target() == "linux" then
		pchheader "%{prj.name}/pch.h"
	end

	pchsource "%{prj.name}/pch.cpp"

	files 
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**/**.h",
		"%{prj.name}/**/**.cpp"
	}

	libdirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/lib"
	}

	includedirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/include",
		"%{prj.name}",
		".",
		"Packages/c++/includes"
	}
	
	links
	{
		"EngineCommons"
	}

	vpaths {
		["Headers/*"] = { "**.h", "**.hpp" },
		["Sources/*"] = {"**.c", "**.cpp"}
	}


	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Game"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release_GAME"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Editor"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release_Editor"
		defines {"LP_API_EXPORTS"}

project "RenderingEngine"
	location "RenderingEngine"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
		toolset "v143"
		links 
		{
			"d3d12",
			"dxgi",
			"D3DCompiler",
			"OpenGL32"
		}
		buildoptions
		{
			"/Zc:__cplusplus"
		}
	elseif os.target() == "linux" then
		pchheader "%{prj.name}/pch.h"
		links 
		{
			"OpenGL",
			"vulkan"
		}
	end

	pchsource "%{prj.name}/pch.cpp"

	files 
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**/**.h",
		"%{prj.name}/**/**.cpp"
	}

	libdirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/lib"
	}

	includedirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/include",
		"Packages/c++/includes",
		"%{prj.name}",
		"."
	}
	
	links
	{
		"EngineCommons",
		"glew32",
		"GlU32",
		"SceneEngine"
	}

	vpaths {
		["Headers/*"] = { "**.h", "**.hpp" },
		["Sources/*"] = {"**.c", "**.cpp"}
	}


	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Game"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release_GAME"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Editor"
		defines {"LP_API_EXPORTS"}
		links
		{
			"ImGui"
		}

	filter "configurations:Release_Editor"
		defines {"LP_API_EXPORTS"}
		links
		{
			"ImGui"
		}

project "ShaderEngine"
	location "ShaderEngine"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
		toolset "v143"
		links 
		{
			"d3d12",
			"dxgi",
			"D3DCompiler",
			"OpenGL32"
		}
		buildoptions
		{
			"/Zc:__cplusplus"
		}
	elseif os.target() == "linux" then
		pchheader "%{prj.name}/pch.h"
		links 
		{
			"OpenGL"
		}
	end

	pchsource "%{prj.name}/pch.cpp"

	files 
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**/**.h",
		"%{prj.name}/**/**.cpp"
	}

	libdirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/lib"
	}

	includedirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/include",
		"%{prj.name}",
		"."
	}
	
	links
	{
		"EngineCommons",
		"glew32",
		"GlU32",
		"volk"
	}

	vpaths {
		["Headers/*"] = { "**.h", "**.hpp" },
		["Sources/*"] = {"**.c", "**.cpp"}
	}


	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Game"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release_GAME"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Editor"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release_Editor"
		defines {"LP_API_EXPORTS"}

project "ScriptingEngine"
	location "ScriptingEngine"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
		toolset "v143"
		links 
		{
			"d3d12",
			"dxgi"
		}
		libdirs
		{
			"Packages/c++/libs/windows"
		}
		buildoptions
		{
			"/Zc:__cplusplus"
		}
	elseif os.target() == "linux" then
		pchheader "%{prj.name}/pch.h"
	end

	pchsource "%{prj.name}/pch.cpp"

	files 
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**/**.h",
		"%{prj.name}/**/**.cpp"
	}

	libdirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/lib"
	}

	includedirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/include",
		"Packages/c++/includes",
		"%{prj.name}",
		"."
	}
	
	links
	{
		"EngineCommons",
		"mono-2.0-sgen"
	}

	vpaths {
		["Headers/*"] = { "**.h", "**.hpp" },
		["Sources/*"] = {"**.c", "**.cpp"}
	}


	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Game"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release_GAME"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Editor"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release_Editor"
		defines {"LP_API_EXPORTS"}

project "SceneEngine"
	location "SceneEngine"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
		toolset "v143"
		libdirs
		{
			"Packages/c++/libs/windows"
		}
		buildoptions
		{
			"/Zc:__cplusplus"
		}
	elseif os.target() == "linux" then
		pchheader "%{prj.name}/pch.h"
	end

	pchsource "%{prj.name}/pch.cpp"

	files 
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**/**.h",
		"%{prj.name}/**/**.cpp"
	}

	libdirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/lib"
	}

	includedirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/include",
		"Packages/c++/includes",
		"%{prj.name}",
		"."
	}
	
	links
	{
		"AssetsEngine",
		"SoundEngine",
		"PhysicsEngine",
		"EngineCommons",
		"ScriptingEngine",
		"EventEngine",
		"yaml-cpp",
		"mono-2.0-sgen"
	}

	vpaths {
		["Headers/*"] = { "**.h", "**.hpp" },
		["Sources/*"] = {"**.c", "**.cpp"}
	}


	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Game"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release_GAME"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Editor"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release_Editor"
		defines {"LP_API_EXPORTS"}

project "AssetsEngine"
	location "AssetsEngine"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
		toolset "v143"
		libdirs
		{
			"Packages/c++/libs/windows"
		}
		buildoptions
		{
			"/Zc:__cplusplus"
		}
	elseif os.target() == "linux" then
		pchheader "%{prj.name}/pch.h"
	end

	pchsource "%{prj.name}/pch.cpp"

	files 
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**/**.h",
		"%{prj.name}/**/**.cpp"
	}

	libdirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/lib"
	}

	includedirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/include",
		"Packages/c++/includes",
		"%{prj.name}",
		"."
	}
	
	links
	{
		"EngineCommons",
		"yaml-cpp"
	}

	vpaths {
		["Headers/*"] = { "**.h", "**.hpp" },
		["Sources/*"] = {"**.c", "**.cpp"}
	}


	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Game"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release_GAME"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Editor"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release_Editor"
		defines {"LP_API_EXPORTS"}

project "EventEngine"
	location "EventEngine"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
		toolset "v143"
		libdirs
		{
			"Packages/c++/libs/windows"
		}
		buildoptions
		{
			"/Zc:__cplusplus"
		}
	elseif os.target() == "linux" then
		pchheader "%{prj.name}/pch.h"
	end

	pchsource "%{prj.name}/pch.cpp"

	files 
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**/**.h",
		"%{prj.name}/**/**.cpp"
	}

	libdirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/lib"
	}

	includedirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/include",
		"Packages/c++/includes",
		"%{prj.name}",
		"."
	}
	
	links
	{
		"EngineCommons"
	}

	vpaths {
		["Headers/*"] = { "**.h", "**.hpp" },
		["Sources/*"] = {"**.c", "**.cpp"}
	}


	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Game"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release_GAME"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Debug_Editor"
		defines {"LP_API_EXPORTS"}

	filter "configurations:Release_Editor"
		defines {"LP_API_EXPORTS"}

if os.target() == "windows" then
	group("C#")
elseif os.target() == "linux" then
	group("C_Sharp")
end
project "LowpEngine"
	location "LowpEngine"
	kind "SharedLib"
	language "C#"


	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/**.cs",
		"%{prj.name}/**/**.cs",
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

project "TestGame"
	location "TestGame"
	kind "SharedLib"
	language "C#"


	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/**.cs",
		"%{prj.name}/**/**.cs",
	}

	links
	{
		"LowpEngine"
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

project "LowpEditor"
	location "LowpEditor"
	kind "SharedLib"
	language "C#"


	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/**.cs",
		"%{prj.name}/**/**.cs",
	}

	links 
	{
		"LowpEngine"
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"


group("C++/Editor")
project "Editor"
	location "Editor"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
		toolset "v143"
		libdirs
		{
			"Packages/c++/libs/windows"
		}
		buildoptions
		{
			"/Zc:__cplusplus"
		}
	elseif os.target() == "linux" then
		pchheader "%{prj.name}/pch.h"
	end

	pchsource "%{prj.name}/pch.cpp"

	files 
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**/**.h",
		"%{prj.name}/**/**.cpp"
	}

	libdirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/lib"
	}

	includedirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/include",
		"%{prj.name}",
		".",
		"Packages/c++/includes"
	}
	
	links
	{
		"Core",
		"AssetsEngine",
		"SoundEngine",
		"PhysicsEngine",
		"RenderingEngine",
		"EngineCommons",
		"ScriptingEngine",
		"EventEngine",
		"SceneEngine",
		"SDL2",
		"spdlog",
		"fmt",
		"volk",
		"mono-2.0-sgen"
	}

	vpaths {
		["Headers/*"] = { "**.h", "**.hpp" },
		["Sources/*"] = {"**.c", "**.cpp"}
	}


	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"



group("C++/Vendors")
project "ImGui"
	location "ImGui"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		cppdialect "C++latest"
		toolset "v143"
		libdirs
		{
			"Packages/c++/libs/windows"
		}
		buildoptions
		{
			"/Zc:__cplusplus"
		}
	elseif os.target() == "linux" then
	end


	files 
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**/**.h",
		"%{prj.name}/**/**.cpp"
	}

	libdirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/lib"
	}

	includedirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/include",
		"%{prj.name}",
		".",
		"Packages/c++/includes"
	}
	
	links
	{
		"EngineCommons",
		"SDL2",
		"spdlog",
		"fmt",
		"volk",
		"mono-2.0-sgen"
	}

	vpaths {
		["Headers/*"] = { "**.h", "**.hpp" },
		["Sources/*"] = {"**.c", "**.cpp"}
	}


	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
		
project "STB"
	location "STB"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		cppdialect "C++latest"
		toolset "v143"
		libdirs
		{
			"Packages/c++/libs/windows"
		}
		buildoptions
		{
			"/Zc:__cplusplus"
		}
	elseif os.target() == "linux" then
	end


	files 
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**/**.h",
		"%{prj.name}/**/**.cpp",
		"%{prj.name}/**.c",
		"%{prj.name}/**/**.c"
	}

	libdirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/lib"
	}

	includedirs
	{
		"Programs/vcpkg/installed/"..vcpkg_arg_dir.."/include",
		"%{prj.name}",
		".",
		"Packages/c++/includes"
	}
	
	links
	{

	}

	vpaths {
		["Headers/*"] = { "**.h", "**.hpp" },
		["Sources/*"] = {"**.c", "**.cpp"}
	}


	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"