cmake_minimum_required(VERSION 3.22)
project(SDL_Project)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
list(APPEND CMAKE_PREFIX_PATH "/home/linuxbrew/.linuxbrew/Cellar/matplotplusplus/1.2.0/lib/cmake/Matplot++")
find_package("Matplot++" REQUIRED)
include_directories(SDL_Project ${SDL2_INCLUDE_DIRS})

add_library(libSDL
        lib/src/Display.cpp
        lib/include/Display.h
        lib/src/Game.cpp
        lib/include/Game.h
        lib/src/Player.cpp
        lib/include/Player.h
        lib/src/Texture.cpp
        lib/include/Texture.h)
target_include_directories(libSDL PRIVATE lib/include)

add_executable(SDL_Project main.cpp)
target_include_directories(SDL_Project PRIVATE lib/include)
target_link_libraries(SDL_Project libSDL ${SDL2_LIBRARIES} Matplot++::matplot)
