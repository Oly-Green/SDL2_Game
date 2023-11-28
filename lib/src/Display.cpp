//
// Created by olive on 11/28/2023.
//

#include "Display.h"

bool Display::init() {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else{
        gameWindow = SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gameWindow == nullptr){
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else{
            gameScreenSurface = SDL_GetWindowSurface(gameWindow);
        }
    }

    return success;
}

bool Display::loadMedia() {
    bool success = true;

    gameImage = SDL_LoadBMP("assets/playerCharacter/sprites.bmp");
    if (gameImage == nullptr){
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
        success = false;
    }
    return success;
}

void Display::showMedia() {
    SDL_BlitSurface(gameImage, NULL, gameScreenSurface, NULL);
    SDL_UpdateWindowSurface(gameWindow);
}

void Display::closeDisplay() {
    SDL_FreeSurface( gameImage);
    gameImage = nullptr;
    SDL_DestroyWindow(gameWindow);
    gameWindow = nullptr;
    SDL_Quit();
}


