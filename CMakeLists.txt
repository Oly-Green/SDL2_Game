cmake_minimum_required(VERSION 3.22)
project(SDL_Project)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

add_subdirectory("cmake-build-debug/FreeImage")

list(APPEND CMAKE_PREFIX_PATH "/home/linuxbrew/.linuxbrew/Cellar/matplotplusplus/1.2.0/lib/cmake/Matplot++")
find_package("Matplot++" REQUIRED)
include_directories(SDL_Project ${SDL_INCLUDE_DIRS})
include_directories(SDL_Project ${SDL2IMAGE_INCLUDE_DIRS})
include_directories(SDL_Project PUBLIC ${FreeImage_SOURCE_DIR}/Source)

include_directories(SDL_Project "/home/linuxbrew/.linuxbrew/Cellar/matplotplusplus/1.2.0/include")

add_library(libSDL
        lib/src/Display.cpp
        lib/include/Display.h
        lib/src/Game.cpp
        lib/include/Game.h
        lib/src/Graph.cpp
        lib/include/Graph.h)
target_include_directories(libSDL PRIVATE lib/include)

add_executable(SDL_Project main.cpp)
target_include_directories(SDL_Project PRIVATE lib/include)
target_link_libraries(SDL_Project libSDL ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} Matplot++::matplot FreeImage)
