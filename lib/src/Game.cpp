//
// Created by olive on 11/29/2023.
//

#include "Game.h"
#include "Graph.h"
#include <vector>

void Game::start(Display display, int animationLength, int animationRate) {
    if( !display.init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else {
        int startTime = SDL_GetTicks();
        int frame = 0;
        //Main Loop
        while(!quit){
            SDL_SetRenderDrawColor( display.getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear(display.getRenderer());
            display.renderGraphs(frame);
            SDL_RenderPresent( display.getRenderer() );
            frame = ((SDL_GetTicks() - startTime) * animationRate / 1000) % animationLength;
            SDL_RenderPresent(display.getRenderer());


            while(SDL_PollEvent(&event) != 0){
                if (event.type == SDL_QUIT){
                    quit = true;
                }
            }
        }
    }
    display.closeDisplay();
}
