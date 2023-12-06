//
// Created by olive on 12/5/2023.
//

#ifndef SDL_PROJECT_GRAPH_H
#define SDL_PROJECT_GRAPH_H

#include <matplot/matplot.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace matplot;

class Graph {
private:
    std::vector<double> y;
    double yMax;
    std::vector<std::vector<double>> frames;
public:
    Graph(std::vector<double> data);
    void generateFrames(double factor);

};


#endif //SDL_PROJECT_GRAPH_H
