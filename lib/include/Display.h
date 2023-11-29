//
// Created by olive on 11/28/2023.
//

#ifndef SDL_PROJECT_DISPLAY_H
#define SDL_PROJECT_DISPLAY_H
#include <SDL.h>
#include <stdio.h>

class Display {
private:
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    SDL_Window* gameWindow = nullptr;
    SDL_Surface* gameScreenSurface = nullptr;
    SDL_Surface* gameImage = nullptr;
public:
//Starts up SDL and creates window
    bool init();

//Loads media
    bool loadMedia(const char* imgFP);

//Shows media on screen
    void showMedia();

//Frees media and shuts down SDL
    void closeDisplay();
};


#endif //SDL_PROJECT_DISPLAY_H
