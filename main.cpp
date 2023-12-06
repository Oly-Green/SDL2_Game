/*This source code copyrighted by Lazy Foo' Productions 2004-2023
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <matplot/matplot.h>
#include <stdio.h>
#include "Display.h"
#include "Game.h"
#include <vector>


int main( int argc, char* args[] ){
    using namespace matplot;

    std::vector<double> y = {75,  91,  105, 123.5, 131,  150,
                             179, 203, 226, 249,   281.5};
    bar(y);

    show();

//    Display display(640, 480);
//    Game game;
//    game.start(display);
    return 0;
}