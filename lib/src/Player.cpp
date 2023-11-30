//
// Created by olive on 11/29/2023.
//

#include "Player.h"

Player::Player(int x, int y, int width, int height)  : SCREEN_WIDTH(width), SCREEN_HEIGHT(height) {
    pX = x;
    pY = y;
    pVelX = 0;
    pVelY = 0;
}

void Player::handleEvents(SDL_Event &e) {
    //Adjust velocity up when key is held down
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0){
        switch (e.key.keysym.sym) {
            case SDLK_UP: pVelY -= PLAYER_VEL; break;
            case SDLK_DOWN: pVelY += PLAYER_VEL; break;
            case SDLK_LEFT: pVelX -= PLAYER_VEL; break;
            case SDLK_RIGHT: pVelX += PLAYER_VEL; break;
        }
    }
    //Readjust velocity back down when key is released
    else if (e.type == SDL_KEYUP && e.key.repeat == 0){
        switch (e.key.keysym.sym) {
            case SDLK_UP: pVelY += PLAYER_VEL; break;
            case SDLK_DOWN: pVelY -= PLAYER_VEL; break;
            case SDLK_LEFT: pVelX += PLAYER_VEL; break;
            case SDLK_RIGHT: pVelX -= PLAYER_VEL; break;
        }
    }
}

void Player::move() {
    pX += pVelX;
    if ((pX < 0) || (pX + PLAYER_WIDTH > SCREEN_WIDTH)){
        pX -= pVelX;
    }

    pY =+ pVelY;
    if((pY < 0 ) || (pY + PLAYER_HEIGHT > SCREEN_HEIGHT)){
        pY -= pVelY;
    }
}

void Player::render() {

}
