//
// Created by kim-jonas on 2023-07-12.
//
#include "math.h"
#include "time.h"
#include "stdlib.h"
#ifndef UNTITLED_INITIALCOND_H
#define UNTITLED_INITIALCOND_H

void initialcondition(int gridsize, double lattice[gridsize][gridsize]){

    srand(time(NULL));
    int len = gridsize-1;

    for (int i = 0; i <= len ; ++i) {
        for (int j = 0; j <= len ; ++j) {

            double randnumber = (double)rand()/(double)RAND_MAX;
            lattice[i][j] = 2*M_PI*randnumber;
        }
    }
}
#endif //UNTITLED_INITIALCOND_H
