//
// Created by olive on 11/29/2023.
//

#ifndef SDL_PROJECT_PLAYER_H
#define SDL_PROJECT_PLAYER_H

#include <SDL.h>

class Player {
private:
    //Screen Dimensions
    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;

    //Player position
    int pX, pY;

    //Current player velocity
    int pVelX, pVelY;

public:
    //Player Dimensions
    static const int PLAYER_HEIGHT = 16;
    static const int PLAYER_WIDTH = 16;

    //Max player move speed
    static const int PLAYER_VEL = 8;

    //Constructor
    Player(int x, int y, int width, int height);

    //handle key press events
    void handleEvents( SDL_Event& e);

    //Move player
    void move();

    //Render player
    void render();
};


#endif //SDL_PROJECT_PLAYER_H
