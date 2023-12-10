//
// Created by olive on 11/28/2023.
//

#ifndef SDL_PROJECT_DISPLAY_H
#define SDL_PROJECT_DISPLAY_H
#include <SDL.h>

#include <FreeImage.h>
#include <stdio.h>
#include <string>

class Display {
private:
    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;

    SDL_Window* gameWindow = nullptr;
    SDL_Renderer* gameRenderer = nullptr;

public:
    Display(int width, int height);

//Starts up SDL and creates window
    bool init();

//Frees media and shuts down SDL
    void closeDisplay();
    void freeTexture(SDL_Texture* texture);

//Loads individual image
    SDL_Surface* loadSurface(std::string path);
    SDL_Texture* loadTexture(std::string path);

//Getter
    SDL_Renderer* getRenderer();

//read individual graph frame from frame index
    void renderGraphs(int frame);

//Read in png files and convert them to bmp
    void PngToBmp(std::string pngFile, std::string bmpFile);
    void convertFrames(int frames);

};





#endif //SDL_PROJECT_DISPLAY_H
