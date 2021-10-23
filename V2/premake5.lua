workspace "V2"
    architecture "x64"
    
    configurations { "Debug",  "Release"}
    outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "V2"
    location "V2"
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
        "%{prj.name}/src"
    }

    filter "system:windows"
        cdialect "C11"
        systemversion "latest"

    filter "configurations:Debug"
        defines {"DEBUG","_CRT_SECURE_NO_WARNINGS"}
        symbols "on"

    filter "configurations:Release"
        defines {"NDEBUG","_CRT_SECURE_NO_WARNINGS"}
        optimize "on"
            