workspace "DevLearningsGame"
   configurations { "Debug", "Release" }

project "Game"
   kind "ConsoleApp"
   language "C++"
   architecture "x86_64"

   binOutputDir = "bin/%{cfg.buildcfg}"
   targetdir("%{binOutputDir}")

   buildoptions {
     "-pedantic",
     "-std=c++17"
   }

   filesPath = "%{wks.location}"
   files {
     "**.cpp",
     "**.h",
     "**.hpp",
     "src/**.h",
     "src/**.cpp"
   }

   includedirs
   {
    "/usr/local/include/SDL2"
   }

   linkoptions
   {
     "-lSDL2-2.0.0",
     "-lSDL2_image-2.0.0"
   }

   libdirs
   {
     "/usr/local/cellar/SDL2/2.0.12_1/lib",
     "/usr/local/Cellar/sdl2_image/2.0.5/lib"
   }

   defines
   {
     "MACOSX"
   }

  postbuildcommands
  {
    ("{COPY} Assets " .. binOutputDir .. "/Assets"),
  }


  filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"

  filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"
