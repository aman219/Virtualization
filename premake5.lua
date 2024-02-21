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
    buildlog("%{wks.location}/log/" ..outputdir.. "%{prj.name}")
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
    buildlog("%{wks.location}/log/" ..outputdir.. "%{prj.name}")
    includedirs {"%{prj.location}/include"}
    files {"%{prj.location}/src/*.c"}

    targetdir ("bin/" ..outputdir.. "/%{prj.name}")
    objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    filter "configurations:Debug"
        symbols "on"
    filter "configurations:Release"
        optimize "on"

project "GLFW"
    location "external/glfw"
    kind "StaticLib"
    language "C"
    staticruntime "off"
    warnings "off"
    buildlog("%{wks.location}/log/" ..outputdir.. "/%{prj.name}")

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.location}/include/GLFW/glfw3.h",
        "%{prj.location}/include/GLFW/glfw3native.h",
        "%{prj.location}/src/glfw_config.h",
        "%{prj.location}/src/context.c",
        "%{prj.location}/src/init.c",
        "%{prj.location}/src/input.c",
        "%{prj.location}/src/monitor.c",

        "%{prj.location}/src/null_init.c",
        "%{prj.location}/src/null_joystick.c",
        "%{prj.location}/src/null_monitor.c",
        "%{prj.location}/src/null_window.c",

        "%{prj.location}/src/platform.c",
        "%{prj.location}/src/vulkan.c",
        "%{prj.location}/src/window.c",
    }

    filter "system:linux"
        pic "On"

        systemversion "latest"
        
        files
        {
            "src/x11_init.c",
            "src/x11_monitor.c",
            "src/x11_window.c",
            "src/xkb_unicode.c",
            "src/posix_module.c",
            "src/posix_time.c",
            "src/posix_thread.c",
            "src/posix_module.c",
            "src/glx_context.c",
            "src/egl_context.c",
            "src/osmesa_context.c",
            "src/linux_joystick.c"
        }

        defines
        {
            "_GLFW_X11"
        }

    filter "system:macosx"
        pic "On"

        files
        {
            "src/cocoa_init.m",
            "src/cocoa_monitor.m",
            "src/cocoa_window.m",
            "src/cocoa_joystick.m",
            "src/cocoa_time.c",
            "src/nsgl_context.m",
            "src/posix_thread.c",
            "src/posix_module.c",
            "src/osmesa_context.c",
            "src/egl_context.c"
        }

        defines
        {
            "_GLFW_COCOA"
        }

    filter "system:windows"
        systemversion "latest"

        files
        {
            "%{prj.location}/src/win32_init.c",
            "%{prj.location}/src/win32_joystick.c",
            "%{prj.location}/src/win32_module.c",
            "%{prj.location}/src/win32_monitor.c",
            "%{prj.location}/src/win32_time.c",
            "%{prj.location}/src/win32_thread.c",
            "%{prj.location}/src/win32_window.c",
            "%{prj.location}/src/wgl_context.c",
            "%{prj.location}/src/egl_context.c",
            "%{prj.location}/src/osmesa_context.c"
        }

        defines 
        { 
            "_GLFW_WIN32",
            "_CRT_SECURE_NO_WARNINGS"
        }

    filter "configurations:Debug"
        --runtime "Debug"
        symbols "on"

    filter { "system:windows", "configurations:Debug" }	
        --runtime "Debug"
        symbols "on"
        --sanitize { "Address" }
        --flags { "NoRuntimeChecks", "NoIncrementalLink" }

    filter "configurations:Release"
        runtime "Release"
        optimize "speed"

    -- filter "configurations:Dist"
    --     runtime "Release"
    --     optimize "speed"
    --     symbols "off"

project "application"
    location "application/"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    buildlog("%{wks.location}/log/" ..outputdir.. "/%{prj.name}")
    
    includedirs {"application/include/",
                "engine/include/",
                "%{wks.location}/external/glad/include",
                "%{wks.location}/external/glfw/include"}


    links { "engine", "glad", "GLFW" }
    files {"application/src/*.cpp", "application/include/*.h"}

    targetdir ("%{wks.location}/bin/" ..outputdir.. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" ..outputdir.. "/%{prj.name}")

    filter "configurations:Debug"
        symbols "on"
    filter "configurations:Release"
        optimize "on"

