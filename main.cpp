/*This source code copyrighted by Lazy Foo' Productions 2004-2023
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <matplot/matplot.h>

#include <FreeImage.h>
#include <stdio.h>
#include <unistd.h>
#include "Display.h"
#include "Game.h"
#include "Graph.h"
#include <vector>


int main( int argc, char* args[] ){
    int frames = 20;
    int animationSpeed = 7;
    Graph graph({100, 200, 300});
    graph.generateFrames(frames);
    Display display(640, 480);
    std::cout << "Sleeping to allow time for frames to convert." << std::endl;
    sleep(3);
    display.convertFrames(frames);
    Game game;
    game.start(display, frames, animationSpeed);
    return 0;
}