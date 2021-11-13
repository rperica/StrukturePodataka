project "Polynomial"
    kind "StaticLib"
    language "c"

    targetdir("%{wks.location}/bin/bin/" ..outputdir.."/%{prj.name}")
    objdir("%{wks.location}/bin/intermediates/" ..outputdir.."/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.c",      
    }

    includedirs
    {
        "src/"
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
