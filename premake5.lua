workspace "tinykern"
    configurations { "Debug", "Release" }

    architecture "x86_64"


project "tinykern"
    kind "ConsoleApp"
    language "C"
    targetdir "iso/boot"
    targetextension ""
    targetname "kernel"

    files { "src/**.h", "src/**.c", "src/**.S", "linker.ld" }
    
    includedirs { "src" }

    buildoptions { 
        "-ffreestanding",
        "-fno-exceptions",
        -- "-fno-rtti",
        "-fno-stack-protector",
        "-fno-builtin",
        "-fno-pie",
        "-Wall",
        "-Wextra",
        "-m32",
        "-std=c99",
        "-nostdlib",
    }

    linkoptions { 
        "-m32",
        "-no-pie",
        "-nostdlib",
        "-nodefaultlibs",
        "-nostartfiles",
        "-Wl,-T," .. "linker.ld",
        "-Wl,--build-id=none"
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
    
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

    -- filter "toolset:gcc or toolset:clang"
    --     buildoptions { "-fno-stack-protector" }
    --     linkoptions { "-fno-builtin" }

    filter "toolset:clang"
        buildoptions { "-fno-integrated-as" }
