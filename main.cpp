/*This source code copyrighted by Lazy Foo' Productions 2004-2023
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <matplot/matplot.h>
#include <stdio.h>
#include "Display.h"
#include "Game.h"
#include "Graph.h"
#include <vector>


int main( int argc, char* args[] ){
    Graph graph({100, 200, 300});
    graph.generateFrames(3);
    Display display(640, 480);
    Game game;
    game.start(display);
    return 0;
}