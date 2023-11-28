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
        if (!display.loadMedia()) {
            printf("Failed to load media!\n");
        } else {
            //Apply the image
            display.showMedia();
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }

        }
    }
    display.closeDisplay();
    return 0;
}