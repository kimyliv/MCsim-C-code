//
// Created by kim-jonas on 2023-07-13.
//

#ifndef UNTITLED_RANDOMWALKFUNCTION_H
#define UNTITLED_RANDOMWALKFUNCTION_H
#include "stdlib.h"
#include "time.h"

void RandomWalkFunction(int *i, int *j, int gridsize){
    int len = gridsize - 1;
    int direction = (int)rand() % 4;

    switch (direction) {
        case 0: // right
            (*i)++;
            break;
        case 1: // left
            (*i)--;
            break;
        case 2: // up
            (*j)++;
            break;
        case 3: // down
            (*j)--;
            break;
    }

    /* Periodic boundary conditions */

    if (*i > len){
        *i = 0;
    }
    if (*i < 0){
        *i = len;
    }
    if (*j > len){
        *j = 0;
    }
    if (*j < 0 ){
        *j = len;
    }
}
#endif //UNTITLED_RANDOMWALKFUNCTION_H
