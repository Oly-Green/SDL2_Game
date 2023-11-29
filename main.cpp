/*This source code copyrighted by Lazy Foo' Productions 2004-2023
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Display.h"


int main( int argc, char* args[] ){

    Display display;
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
            bool quit = false;
            SDL_Event event;
            while(!quit){
                while(SDL_PollEvent(&event) != 0){
                    if (event.type == SDL_QUIT){
                        quit = true;
                    }
                }
                //Apply the image
                display.showMedia();
            }
        }
    }
    display.closeDisplay();
    return 0;
}