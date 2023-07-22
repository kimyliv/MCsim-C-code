//
// Created by kim-jonas on 2023-07-13.
//

#ifndef UNTITLED_MAGNETIZATION_H
#define UNTITLED_MAGNETIZATION_H
#include "math.h"

double magnetization(int gridsize, double lattice[gridsize][gridsize]){
    int len = gridsize - 1;
    double magcos = 0, magsin = 0;

    for (int i = 0; i <= len; ++i) {
        for (int j = 0; j <= len ; ++j) {
            magcos += cos(lattice[i][j]);
            magsin += sin(lattice[i][j]);
        }
    }
    return sqrt(magcos*magcos + magsin*magsin) / (gridsize*gridsize);
}

#endif //UNTITLED_MAGNETIZATION_H
