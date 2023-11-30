//
// Created by olive on 11/29/2023.
//

#include "Game.h"

void Game::start(Display display) {
    if( !display.init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else {
        //Load media
        if (!display.loadMedia("assets/playerCharacter/lilguy.bmp")) {
            printf("Failed to load media!\n");
        } else {

            //Game Loop
            while(!quit){
                while(SDL_PollEvent(&event) != 0){
                    if (event.type == SDL_QUIT){
                        quit = true;
                    }
                    else if (event.type == SDL_KEYDOWN){
                        display.updateSurface(event);
                    }
                }
                //Apply the image
                display.showMedia();
            }
        }
    }
    display.closeDisplay();
}