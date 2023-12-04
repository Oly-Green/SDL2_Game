//
// Created by olive on 12/1/2023.
//

#include "Texture.h"
//
//SDL_Surface *Texture::loadSurface(Display& display, std::string path) {
//
////    SDL_Surface* optimizedSurface = nullptr;
//    SDL_Surface* surface = SDL_LoadBMP(path.c_str());
//    if (surface == nullptr){
//        printf("Unable to load", path.c_str(), SDL_GetError());
//    }
//    else{
////        optimizedSurface = SDL_ConvertSurface(surface, display.getWindowSurface()->format, 0);
//    }
//
//    return surface;
//}
//
//SDL_Texture *Texture::loadTexture(Display& display, std::string path) {
//    SDL_Texture* texture = SDL_CreateTextureFromSurface()
//
//    return nullptr;
//}
//
//
//bool Texture::load(Display &display) {
//    bool success = true;
//    playerTexture = loadTexture(display, "assets/playerCharacter/lilguy.bmp");
//    if (playerTexture == nullptr){
//        printf("Failed to load player", SDL_GetError());
//        success = false;
//    }
//    return success;
//}
//
//SDL_Texture *Texture::getPlayerTexture() {
//    return playerTexture;
//}
//
Texture::Texture(Display& display) {
    texWidth = 0;
    texHeight = 0;
    gameDisplay = &display;
}

Texture::~Texture() {
    free();
}

bool Texture::loadFile(std::string path) {
    free();
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = gameDisplay->loadSurface(path.c_str());
    if (loadedSurface == nullptr){
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), SDL_GetError() );
    }
    else{
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0x65, 0xFF, 0));
        newTexture = SDL_CreateTextureFromSurface(gameDisplay->getRenderer(), loadedSurface);
        if (newTexture == nullptr){
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else{
            texWidth = loadedSurface->w;
            texHeight = loadedSurface->h;
        }
        SDL_FreeSurface(loadedSurface);
    }
    gameTexture = newTexture;
    return gameTexture != nullptr;
}

void Texture::free() {
    if (gameTexture != nullptr){
        SDL_DestroyTexture(gameTexture);
        gameTexture = nullptr;
        texWidth = 0;
        texHeight = 0;
    }
}

void Texture::render(int x, int y) {
    SDL_Rect renderQuad = {x, y, texWidth, texHeight};
    SDL_RenderCopy(gameDisplay->getRenderer(), gameTexture, nullptr, &renderQuad);
}

int Texture::getWidth() {
    return texWidth;
}

int Texture::getHeight() {
    return texHeight;
}
