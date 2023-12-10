//
// Created by olive on 11/28/2023.
//

#include <iostream>
#include "Display.h"

Display::Display(int width, int height)
        : SCREEN_WIDTH(width), SCREEN_HEIGHT(height) {
    FreeImage_Initialise();
}

void Display::init() {
    SDL_Init(SDL_INIT_VIDEO);
    gameWindow = SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
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
    return loadedSurface;
}

SDL_Texture *Display::loadTexture(std::string path) {
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = loadSurface(path.c_str());
    newTexture = SDL_CreateTextureFromSurface(gameRenderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
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


