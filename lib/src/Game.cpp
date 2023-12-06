//
// Created by olive on 11/29/2023.
//

#include "Game.h"
#include "Graph.h"
#include <vector>

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
            int animationRate = 3;
            int animationLength = 3;
            int startTime = SDL_GetTicks();
            int frame = 0;
            //Game Loop
            while(!quit){
                SDL_SetRenderDrawColor( display.getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear(display.getRenderer());
                //SDL_RenderCopy(display.getRenderer(), display.getPlayerTexture(), nullptr, nullptr);

                //display.renderBackground();
//                display.renderPlayer(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 3);

                //display.playWalkAnimation(frame);
                display.renderGraphs(frame);
                SDL_RenderPresent( display.getRenderer() );
                frame = ((SDL_GetTicks() - startTime) * animationRate / 1000) % animationLength;
                SDL_RenderPresent(display.getRenderer());


                while(SDL_PollEvent(&event) != 0){
                    if (event.type == SDL_QUIT){
                        quit = true;
                    }

//                    else if (event.type == SDL_KEYDOWN){
//                        display.updateSurface(event);
//                    }
                }



//                //Apply the image
//                display.showMedia();
            }
        }
    }
    display.closeDisplay();
}
