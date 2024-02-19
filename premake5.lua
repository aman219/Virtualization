workspace "virtualization"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "application"

    

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "engine"
    location "engine/"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    includedirs {"engine/include"}
    files {"engine/src/*.cpp", "engine/include/*.h"}

    targetdir ("bin/" ..outputdir.. "/%{prj.name}")
    objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    filter "configurations:Debug"
        symbols "on"
    filter "configurations:Release"
        optimize "on"

project "glad"
    location "external/glad"
    kind "StaticLib"
    language "C"
    includedirs {"%{prj.location}/include"}
    files {"%{prj.location}/src/*.c"}

    targetdir ("bin/" ..outputdir.. "/%{prj.name}")
    objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    filter "configurations:Debug"
        symbols "on"
    filter "configurations:Release"
        optimize "on"

include "external/glfw"

project "application"
    location "application/"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    
    includedirs {"application/include/",
                "engine/include/",
                "%{wks.location}/external/glad/include",
                "%{wks.location}/external/glfw/include"}


    links { "engine", "glad", "GLFW" }
    files {"application/src/*.cpp", "application/include/*.h"}

    targetdir ("bin/" ..outputdir.. "/%{prj.name}")
    objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    filter "configurations:Debug"
        symbols "on"
    filter "configurations:Release"
        optimize "on"

