//
// Created by olive on 11/28/2023.
//

#include <iostream>
#include "Display.h"

Display::Display(int width, int height)
        : SCREEN_WIDTH(width), SCREEN_HEIGHT(height) {
    FreeImage_Initialise();
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
            gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if (gameRenderer == nullptr){
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else{
                SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            }
        }
    }

    return success;
}

void Display::closeDisplay() {
    SDL_DestroyRenderer(gameRenderer);
    gameRenderer = nullptr;
    SDL_DestroyWindow(gameWindow);
    gameWindow = nullptr;
    SDL_Quit();
    FreeImage_DeInitialise();
}

SDL_Surface *Display::loadSurface(std::string path) {

    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
    if (loadedSurface == nullptr){
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }
    return loadedSurface;
}

SDL_Texture *Display::loadTexture(std::string path) {
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = loadSurface(path.c_str());
    if (loadedSurface == nullptr){
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), SDL_GetError() );
    }
    else{
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

void Display::freeTexture(SDL_Texture* texture) {
    if (texture != nullptr){
        SDL_DestroyTexture(texture);
    }
}

void Display::renderGraphs(int frame) {
    std::string fileName = "graphFrames/bmpFrames/frame";
    fileName+=std::to_string(frame);
    fileName+=".bmp";
    SDL_Texture* graphTex = loadTexture(fileName);

    SDL_Point size;
    SDL_QueryTexture(graphTex, NULL, NULL, &size.x, &size.y);
    SDL_Rect renderQuad = {0, 0, size.x, size.y};
    SDL_RenderCopy(gameRenderer, graphTex, nullptr, &renderQuad);
    freeTexture(graphTex);
}

void Display::PngToBmp(std::string pngFile, std::string bmpFile) {
    FIBITMAP* bmp = FreeImage_Load(FIF_PNG, pngFile.c_str());
    if (bmp == nullptr){
        std::cout << "Error loading PNG image: " << pngFile << std::endl;
        return;
    }
    FIBITMAP* convertedBMP = FreeImage_ConvertTo24Bits(bmp);
    FreeImage_Unload(bmp);

    FreeImage_Save(FIF_BMP, convertedBMP, bmpFile.c_str(), BMP_DEFAULT);
}

void Display::convertFrames(int frames) {
    for (int i = 0; i < frames; ++i) {
        std::string PNGfileName = "graphFrames/pngFrames/frame";
        PNGfileName+=std::to_string(i);
        PNGfileName+=".png";

        std::string BMPfileName = "graphFrames/bmpFrames/frame";
        BMPfileName+=std::to_string(i);
        BMPfileName+=".bmp";

        PngToBmp(PNGfileName, BMPfileName);
    }
}


