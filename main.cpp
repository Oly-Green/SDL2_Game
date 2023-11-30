/*This source code copyrighted by Lazy Foo' Productions 2004-2023
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Display.h"
#include "Game.h"


int main( int argc, char* args[] ){
    Display display(640, 480);
    Game game;
    game.start(display);
    return 0;
}