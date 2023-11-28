cmake_minimum_required(VERSION 3.22)
project(SDL_Project)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(SDL_Project ${SDL2_INCLUDE_DIRS})

add_library(libSDL
        lib/src/Display.cpp
        lib/include/Display.h)
target_include_directories(libSDL PRIVATE lib/include)

add_executable(SDL_Project main.cpp)
target_include_directories(SDL_Project PRIVATE lib/include)
target_link_libraries(SDL_Project ${SDL2_LIBRARIES} libSDL)
