//
// Created by olive on 12/5/2023.
//

#include "Graph.h"


Graph::Graph(std::vector<double> data) {
    y = data;
}

void Graph::generateFrames(double factor) {
    for (int i = 0; i < factor; ++i) {
        frames.push_back(std::vector<double>());
        for (int j = 0; j < y.size(); ++j) {
            double divY = (y[j]/factor)*(i+1);
            frames[i].push_back(divY);
//            std::cout << divY << ", ";
        }
//        std::cout << std::endl;
    }

    yMax = max(y);
    ylim({0,yMax});

    for (int k = 0; k < frames.size(); ++k) {
        std::string fileName = "graphFrames/pngFrames/frame";
        fileName+=std::to_string(k);
        fileName+=".png";
//        std::cout << fileName <<std::endl;
        bar(frames[k]);
        save(fileName);
    }
}

