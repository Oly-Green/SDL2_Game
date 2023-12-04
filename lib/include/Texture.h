//
// Created by olive on 12/1/2023.
//

#ifndef SDL_PROJECT_TEXTURE_H
#define SDL_PROJECT_TEXTURE_H
#include <string>
#include "Display.h"

class Display;
class Texture {
private:
    SDL_Texture* gameTexture = nullptr;
    int texWidth;
    int texHeight;
    Display* gameDisplay = nullptr;
//    SDL_Surface* loadSurface(Display& display, std::string path);
//    SDL_Texture* loadTexture(Display& display, std::string path);
//
//    SDL_Texture* playerTexture = nullptr;
public:
    Texture(Display& display);
    ~Texture();
    bool loadFile(std::string path);
    void free();
    void render(int x, int y);
    int getWidth();
    int getHeight();
//    bool load(Display& display);
//    SDL_Texture* getPlayerTexture();
};


#endif //SDL_PROJECT_TEXTURE_H
