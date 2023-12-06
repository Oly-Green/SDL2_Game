//
// Created by olive on 11/28/2023.
//

#include "Display.h"

Display::Display(int width, int height)
        : SCREEN_WIDTH(width), SCREEN_HEIGHT(height) {

}

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
            gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if (gameRenderer == nullptr){
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else{
                SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

//                //Initialize PNG loading
//                int imgFlags = IMG_INIT_PNG;
//                if( !( IMG_Init( imgFlags ) & imgFlags ) )
//                {
//                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
//                    success = false;
//                }
            }
        }
    }

    return success;
}

bool Display::loadMedia(const char* imgFP) {
    bool success = true;

    playerTexture = loadTexture("assets/playerCharacter/lilguy.bmp");
    backgroundTexture = loadTexture("assets/background/Grass_Sample.bmp");
    playerSpriteSheet = loadTexture("assets/playerCharacter/sprites.bmp");


    int playerSpriteWidth = 16;
    int playerSpriteHeight = 16;
    //Set sprite clips
    gameSpriteClips[ 0 ].x = 0;
    gameSpriteClips[ 0 ].y = 0;
    gameSpriteClips[ 0 ].w = playerSpriteWidth;
    gameSpriteClips[ 0 ].h = playerSpriteHeight;

    gameSpriteClips[ 1 ].x = playerSpriteWidth;
    gameSpriteClips[ 1 ].y = 0;
    gameSpriteClips[ 1 ].w = playerSpriteWidth;
    gameSpriteClips[ 1 ].h = playerSpriteHeight;

    gameSpriteClips[ 2 ].x = playerSpriteWidth*2;
    gameSpriteClips[ 2 ].y = 0;
    gameSpriteClips[ 2 ].w = playerSpriteWidth;
    gameSpriteClips[ 2 ].h = playerSpriteHeight;

    gameSpriteClips[ 3 ].x = playerSpriteWidth*3;
    gameSpriteClips[ 3 ].y = 0;
    gameSpriteClips[ 3 ].w = playerSpriteWidth;
    gameSpriteClips[ 3 ].h = playerSpriteHeight;
//    playerTexture = loadTexture(imgFP);
//    if (playerTexture == nullptr){
//        printf( "Failed to load texture image!\n" );
//        success = false;
//    }


//    //Load default surface
//    gameKeyPressSurface[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("assets/TestingAssets/default.bmp");
//    if (gameKeyPressSurface[KEY_PRESS_SURFACE_DEFAULT] == nullptr){
//        printf( "Failed to load default image!\n" );
//        success = false;
//    }
//
//    //Load up surface
//    gameKeyPressSurface[KEY_PRESS_SURFACE_UP] = loadSurface("assets/TestingAssets/up.bmp");
//    if (gameKeyPressSurface[KEY_PRESS_SURFACE_UP] == nullptr){
//        printf( "Failed to load up image!\n" );
//        success = false;
//    }
//
//    //Load down surface
//    gameKeyPressSurface[KEY_PRESS_SURFACE_DOWN] = loadSurface("assets/TestingAssets/down.bmp");
//    if (gameKeyPressSurface[KEY_PRESS_SURFACE_DOWN] == nullptr){
//        printf( "Failed to load down image!\n" );
//        success = false;
//    }
//
//    //Load left surface
//    gameKeyPressSurface[KEY_PRESS_SURFACE_LEFT] = loadSurface("assets/TestingAssets/left.bmp");
//    if (gameKeyPressSurface[KEY_PRESS_SURFACE_LEFT] == nullptr){
//        printf( "Failed to load left image!\n" );
//        success = false;
//    }
//
//    //Load right surface
//    gameKeyPressSurface[KEY_PRESS_SURFACE_RIGHT] = loadSurface("assets/TestingAssets/right.bmp");
//    if (gameKeyPressSurface[KEY_PRESS_SURFACE_RIGHT] == nullptr){
//        printf( "Failed to load right image!\n" );
//        success = false;
//    }
//
//    gameCurrentSurface = gameKeyPressSurface[KEY_PRESS_SURFACE_DEFAULT];

    return success;
}

void Display::showMedia() {
    SDL_BlitSurface(gameCurrentSurface, NULL, gameScreenSurface, NULL);
    SDL_UpdateWindowSurface(gameWindow);
}

void Display::closeDisplay() {
    freeTexture(playerTexture);
    playerTexture = nullptr;
    freeTexture(backgroundTexture);
    backgroundTexture = nullptr;

    SDL_DestroyRenderer(gameRenderer);
    gameRenderer = nullptr;
    SDL_FreeSurface( gameCurrentSurface);
    SDL_DestroyWindow(gameWindow);
    gameWindow = nullptr;
    SDL_Quit();
}

SDL_Surface *Display::loadSurface(std::string path) {

    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
    if (loadedSurface == nullptr){
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }
    return loadedSurface;
}

void Display::updateSurface(SDL_Event e) {
    //Select surfaces based on key press
    switch( e.key.keysym.sym )
    {
        case SDLK_UP:
            gameCurrentSurface = gameKeyPressSurface[ KEY_PRESS_SURFACE_UP ];
            break;

        case SDLK_DOWN:
            gameCurrentSurface = gameKeyPressSurface[ KEY_PRESS_SURFACE_DOWN ];
            break;

        case SDLK_LEFT:
            gameCurrentSurface = gameKeyPressSurface[ KEY_PRESS_SURFACE_LEFT ];
            break;

        case SDLK_RIGHT:
            gameCurrentSurface = gameKeyPressSurface[ KEY_PRESS_SURFACE_RIGHT ];
            break;

        default:
            gameCurrentSurface = gameKeyPressSurface[ KEY_PRESS_SURFACE_DEFAULT ];
            break;
    }
}

SDL_Texture *Display::loadTexture(std::string path) {

    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = loadSurface(path.c_str());
    if (loadedSurface == nullptr){
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), SDL_GetError() );
    }
    else{
//        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0x65, 0xFF, 0));
        newTexture = SDL_CreateTextureFromSurface(gameRenderer, loadedSurface);
        if (newTexture == nullptr){
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

SDL_Renderer *Display::getRenderer() {
    return gameRenderer;
}

void Display::renderTexture(int x, int y, SDL_Texture* texture) {
    SDL_Point size;
    SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
    SDL_Rect renderQuad = {x, y, size.x, size.y};
    SDL_RenderCopy(gameRenderer, texture, nullptr, &renderQuad);
}

void Display::renderBackground() {
    SDL_Point size;
    SDL_QueryTexture(backgroundTexture, NULL, NULL, &size.x, &size.y);
    SDL_Rect renderQuad = {0, 0, size.x, size.y};
    SDL_RenderCopy(gameRenderer, backgroundTexture, nullptr, &renderQuad);
}

void Display::renderPlayer(int x, int y, int rescaleFactor) {
    SDL_SetHint (SDL_HINT_RENDER_SCALE_QUALITY, 0);
    SDL_Point size;
    SDL_QueryTexture(playerTexture, NULL, NULL, &size.x, &size.y);
    SDL_Rect renderQuad = {x, y, size.x*rescaleFactor, size.y*rescaleFactor};
    SDL_RenderCopy(gameRenderer, playerTexture, nullptr, &renderQuad);
}

void Display::freeTexture(SDL_Texture* texture) {
    if (texture != nullptr){
        SDL_DestroyTexture(texture);
    }
}

void Display::playWalkAnimation(int frame) {
    SDL_Rect* currentClip = &gameSpriteClips[frame];
    int x = ( SCREEN_WIDTH - currentClip->w ) / 2;
    int y = ( SCREEN_HEIGHT - currentClip->h ) / 2;

//    SDL_Point size;
//    SDL_QueryTexture(playerSpriteSheet, NULL, NULL, &size.x, &size.y);
    SDL_Rect renderQuad = {x, y, 48, 48};
    SDL_RenderCopy(gameRenderer, playerSpriteSheet, currentClip, &renderQuad);
}

void Display::renderGraphs(int frame) {
    std::string fileName = "graphFrames/frame";
    fileName+=std::to_string(frame);
    fileName+=".bmp";
    SDL_Texture* graphTex = loadTexture(fileName);

    SDL_Point size;
    SDL_QueryTexture(graphTex, NULL, NULL, &size.x, &size.y);
    SDL_Rect renderQuad = {0, 0, size.x, size.y};
    SDL_RenderCopy(gameRenderer, graphTex, nullptr, &renderQuad);
}

