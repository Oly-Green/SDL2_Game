//
// Created by olive on 11/29/2023.
//

#ifndef SDL_PROJECT_GAME_H
#define SDL_PROJECT_GAME_H

#include <SDL.h>
#include <stdio.h>
#include "Display.h"


class Game {
private:
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    bool quit = false;
    SDL_Event event;


public:
    void start(Display display);
};


#endif //SDL_PROJECT_GAME_H
