//
// Created by olive on 11/28/2023.
//

#ifndef SDL_PROJECT_DISPLAY_H
#define SDL_PROJECT_DISPLAY_H
#include <SDL.h>
#include <stdio.h>
#include <string>

class Display {
private:
    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;

    //Key press surfaces constants
    enum KeyPressSurfaces
    {
        KEY_PRESS_SURFACE_DEFAULT,
        KEY_PRESS_SURFACE_UP,
        KEY_PRESS_SURFACE_DOWN,
        KEY_PRESS_SURFACE_LEFT,
        KEY_PRESS_SURFACE_RIGHT,
        KEY_PRESS_SURFACE_TOTAL
    };

    SDL_Window* gameWindow = nullptr;
    SDL_Surface* gameScreenSurface = nullptr;
    SDL_Surface* gameKeyPressSurface[KEY_PRESS_SURFACE_TOTAL];
    SDL_Surface * gameCurrentSurface = nullptr;

public:
    Display(int width, int height);

//Starts up SDL and creates window
    bool init();

//Loads media
    bool loadMedia(const char* imgFP);

//Shows media on screen
    void showMedia();

//Frees media and shuts down SDL
    void closeDisplay();

//Loads individual image
    SDL_Surface* loadSurface(std::string path);

//Update current surface based on keypress event
    void updateSurface(SDL_Event e);
};




#endif //SDL_PROJECT_DISPLAY_H
