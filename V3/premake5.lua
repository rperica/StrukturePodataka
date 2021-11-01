workspace "V3"
    architecture "x64"
    startproject "V3"
    configurations { "Debug",  "Release"}
    outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "PersonList"
    location "PersonList"
    kind "StaticLib"
    language "c"

    targetdir("bin/bin/" ..outputdir.."/%{prj.name}")
    objdir("bin/intermediates/" ..outputdir.."/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.c",      
    }

    includedirs
    {
        "%{prj.name}/src"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"    
    }

    filter "system:windows"
    cdialect "C11"
    systemversion "latest"

filter "configurations:Debug"
    defines {"DEBUG"}
    symbols "on"

filter "configurations:Release"
    defines {"NDEBUG"}
    optimize "on"

project "V3"
    location "V3"
    kind "ConsoleApp"
    language "c"

    targetdir("bin/bin/" ..outputdir.."/%{prj.name}")
    objdir("bin/intermediates/" ..outputdir.."/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.c",      
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{wks.location}/PersonList/src"
    }

    links
    {
        "PersonList"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }
    
    filter "system:windows"
        cdialect "C11"
        systemversion "latest"

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "on"

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "on"
