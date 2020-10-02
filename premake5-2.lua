workspace "GE777"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GE777"
	location "GE777"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "%{prj.name}")
	objdir("bin-int/" .. outputdir .. "%{prj.name}")

	files
	{
	"%(prj.name)/src/**.h",
	"%(prj.name)/src/**.cpp"
	}

	includedirs
	{

	 "%(prj.name)/vendor/spdlog/include/spdlog;"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
		GE_PLATFORM_WINDOWS,
		GE_BUILD_DLL,
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "GE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GE_Release"
		symbols "On"

	filter "configurations:Dist"
		defines "GE_Dist"
		symbols "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "%{prj.name}")
	objdir("bin-int/" .. outputdir .. "%{prj.name}")

	files
	{
	"%(prj.name)/src/**.h",
	"%(prj.name)/src/**.cpp"
	}

	includedirs
	{
	 "GE777/vendor/spdlog/include/spdlog;",
	 "GE777/src;"
	}

	links
	{
		"GE777"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
		GE_PLATFORM_WINDOWS,
		
		}

		
	filter "configurations:Debug"
		defines "GE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GE_Release"
		symbols "On"

	filter "configurations:Dist"
		defines "GE_Dist"
		symbols "On"