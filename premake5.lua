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
		"Release"
	}
	platforms { "x86", "x64", "ARM", "ARM64" }
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	vcpkg_arg_dir = determine_architecture().."-"..determine_os();
			
group "C++"
project "Core"
	location "Core"
	kind "StaticLib"
	language "C++"
	toolset "v143"
	buildoptions
	{
		"/Zc:__cplusplus"
	}

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
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
		"SoundEngine",
		"PhysicsEngine",
		"RenderingEngine",
		"EngineCommons",
		"ScriptingEngine",
		"SDL2",
		"spdlog",
		"fmt"
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
		symbols "On"
		defines {"DEBUG"}

	filter "configurations:Release"
		optimize "On"
		defines {"RELEASE"}

project "EngineCommons"
	location "EngineCommons"
	kind "StaticLib"
	language "C++"
	toolset "v143"
	buildoptions
	{
		"/Zc:__cplusplus"
	}

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
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
		symbols "On"
		defines {"DEBUG"}

	filter "configurations:Release"
		optimize "On"
		defines {"RELEASE"}

project "Launcher"
	location "Launcher"
	kind "ConsoleApp"
	language "C++"
	toolset "v143"
	buildoptions
	{
		"/Zc:__cplusplus"
	}

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")



	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
		libdirs
		{
			"Packages/c++/libs/windows"
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
		"Core"
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
		symbols "On"
		defines {"DEBUG"}

	filter "configurations:Release"
		optimize "On"
		defines {"RELEASE"}

project "Editor"
	location "Editor"
	kind "StaticLib"
	language "C++"
	toolset "v143"
	buildoptions
	{
		"/Zc:__cplusplus"
	}

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
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
		symbols "On"
		defines {"DEBUG"}

	filter "configurations:Release"
		optimize "On"
		defines {"RELEASE"}

-- C++ Subsystems that are used in the engine
group "C++/Subsystem"
project "SoundEngine"
	location "SoundEngine"
	kind "StaticLib"
	language "C++"
	toolset "v143"
	buildoptions
	{
		"/Zc:__cplusplus"
	}

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
		libdirs
		{
			"Packages/c++/libs/windows"
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
		"EngineCommons",
		"Packages/c++/includes"
	}
	
	links
	{
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
		symbols "On"
		defines { "DEBUG"}

	filter "configurations:Release"
		optimize "On"
		defines {"RELEASE"}

project "PhysicsEngine"
	location "PhysicsEngine"
	kind "StaticLib"
	language "C++"
	toolset "v143"
	buildoptions
	{
		"/Zc:__cplusplus"
	}

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
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
		symbols "On"
		defines {"DEBUG"}

	filter "configurations:Release"
		optimize "On"
		defines {"RELEASE"}

project "RenderingEngine"
	location "RenderingEngine"
	kind "StaticLib"
	language "C++"
	toolset "v143"
	buildoptions
	{
		"/Zc:__cplusplus"
	}

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
		links 
		{
			"d3d12",
			"dxgi",
			"D3DCompiler",
			"OpenGL32"
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
		"%{prj.name}",
		"."
	}
	
	links
	{
		"EngineCommons",
		"glew32",
		"GlU32"
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
		symbols "On"
		defines {"DEBUG"}

	filter "configurations:Release"
		optimize "On"
		defines {"RELEASE"}

project "ScriptingEngine"
	location "ScriptingEngine"
	kind "StaticLib"
	language "C++"
	toolset "v143"
	buildoptions
	{
		"/Zc:__cplusplus"
	}

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
		links 
		{
			"d3d12",
			"dxgi"
		}
		libdirs
		{
			"Packages/c++/libs/windows"
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
		symbols "On"
		defines { "DEBUG"}

	filter "configurations:Release"
		optimize "On"
		defines {"RELEASE"}

project "SceneEngine"
	location "SceneEngine"
	kind "StaticLib"
	language "C++"
	toolset "v143"
	buildoptions
	{
		"/Zc:__cplusplus"
	}

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
		libdirs
		{
			"Packages/c++/libs/windows"
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
		symbols "On"
		defines { "DEBUG"}

	filter "configurations:Release"
		optimize "On"
		defines {"RELEASE"}

project "AssetsEngine"
	location "AssetsEngine"
	kind "StaticLib"
	language "C++"
	toolset "v143"
	buildoptions
	{
		"/Zc:__cplusplus"
	}

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	if os.target() == "windows" then
		pchheader "pch.h"
		cppdialect "C++latest"
		libdirs
		{
			"Packages/c++/libs/windows"
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
		symbols "On"
		defines { "DEBUG"}

	filter "configurations:Release"
		optimize "On"
		defines {"RELEASE"}

group("C#")
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

	filter "configurations:Debug"
		symbols "On"
		defines { "DEBUG"}

	filter "configurations:Release"
		optimize "On"
		defines {"RELEASE"}

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

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		symbols "On"
		defines { "DEBUG"}

	filter "configurations:Release"
		optimize "On"
		defines {"RELEASE"}