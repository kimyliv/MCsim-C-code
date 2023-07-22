//
// Created by kim-jonas on 2023-07-13.
//

#ifndef UNTITLED_ENERGYDIFF_H
#define UNTITLED_ENERGYDIFF_H
#include "math.h"

double Energydiff(int gridsize, double lattice[gridsize][gridsize], int i, int j, double newAngle, int couplingconst){
    int len = gridsize - 1;
    double E1 = 0, E2 = 0;

    if (i == 0 && j == 0) {
        E1 = -couplingconst * (cos(lattice[i][j] - lattice[i][len]) + cos(lattice[i][j] - lattice[len][j]) +
                                   cos(lattice[i][j] - lattice[i + 1][j]) +
                                   cos(lattice[i][j] - lattice[i][j + 1]));
        E2 = -couplingconst * (cos(newAngle - lattice[i][len]) + cos(newAngle - lattice[len][j]) +
                              cos(newAngle  - lattice[i + 1][j]) +
                              cos(newAngle  - lattice[i][j + 1]));
    }
    else if(i == 0 && j == len){
        E1 = -couplingconst * (cos(lattice[i][j] - lattice[len][j]) + cos(lattice[i][j]-lattice[i+1][j])
                                   + cos(lattice[i][j] - lattice[i][j-1]) + cos(lattice[i][j] - lattice[i][0]));
        E2 = -couplingconst * (cos(newAngle - lattice[len][j]) + cos(newAngle-lattice[i+1][j])
                               + cos(newAngle - lattice[i][j-1]) + cos(newAngle - lattice[i][0]));
    }
    else if (i == len && j == 0){
        E1 = -couplingconst * (cos(lattice[i][j] - lattice[i-1][j]) + cos(lattice[i][j] - lattice[0][j])
                                   + cos(lattice[i][j] - lattice[i][j+1]) + cos(lattice[i][j] - lattice[i][len]));
        E2 = -couplingconst * (cos(newAngle- lattice[i-1][j]) + cos(newAngle - lattice[0][j])
                               + cos(newAngle - lattice[i][j+1]) + cos(newAngle- lattice[i][len]));

    }
    else if (i == len && j == len){
        E1 = -couplingconst * (cos(lattice[i][j] - lattice[i-1][j]) + cos(lattice[i][j] - lattice[i][j-1])
                                   + cos(lattice[i][j] - lattice[0][j]) + cos(lattice[i][j] - lattice[i][0]));
        E2 = -couplingconst * (cos(newAngle - lattice[i-1][j]) + cos(newAngle - lattice[i][j-1])
                               + cos(newAngle- lattice[0][j]) + cos(newAngle - lattice[i][0]));
    }
    else if (i == 0){
        E1 = -couplingconst * (cos(lattice[i][j] - lattice[len][j]) + cos(lattice[i][j] - lattice[i+1][j])
                                   + cos(lattice[i][j]-lattice[i][j+1]) + cos(lattice[i][j]-lattice[i][j-1]));
        E2 = -couplingconst * (cos(newAngle - lattice[len][j]) + cos(newAngle - lattice[i+1][j])
                               + cos(newAngle-lattice[i][j+1]) + cos(newAngle-lattice[i][j-1]));
    }
    else if (i == len){
        E1 = -couplingconst * (cos(lattice[i][j] - lattice[i-1][j]) + cos(lattice[i][j] - lattice[0][j])
                                   + cos(lattice[i][j] - lattice[i][j-1]) + cos(lattice[i][j] - lattice[i][j+1]));
        E2 = -couplingconst * (cos(newAngle - lattice[i-1][j]) + cos(newAngle - lattice[0][j])
                               + cos(newAngle - lattice[i][j-1]) + cos(newAngle - lattice[i][j+1]));
    }
    else if (j == 0){
        E1 = -couplingconst * (cos(lattice[i][j] - lattice[i+1][j]) + cos(lattice[i][j] - lattice[i-1][j])
                                   + cos(lattice[i][j] - lattice[i][j+1]) + cos(lattice[i][j]- lattice[i][len]));
        E2 = -couplingconst * (cos(newAngle - lattice[i+1][j]) + cos(newAngle - lattice[i-1][j])
                               + cos(newAngle - lattice[i][j+1]) + cos(newAngle- lattice[i][len]));
    }
    else if (j == len){
        E1 = -couplingconst * (cos(lattice[i][j] - lattice[i+1][j]) + cos(lattice[i][j] - lattice[i-1][j])
                                   + cos(lattice[i][j] - lattice[i][j-1]) + cos(lattice[i][j] - lattice[i][0]));
        E2 = -couplingconst * (cos(newAngle - lattice[i+1][j]) + cos(newAngle - lattice[i-1][j])
                               + cos(newAngle - lattice[i][j-1]) + cos(newAngle - lattice[i][0]));
    }
    else{
        E1 = -couplingconst * (cos(lattice[i][j] - lattice[i-1][j]) + cos(lattice[i][j] - lattice[i+1][j])
                                   + cos(lattice[i][j] - lattice[i][j-1]) + cos(lattice[i][j] - lattice[i][j+1]));
        E2 = -couplingconst * (cos(newAngle - lattice[i-1][j]) + cos(newAngle - lattice[i+1][j])
                               + cos(newAngle - lattice[i][j-1]) + cos(newAngle - lattice[i][j+1]));
    }
    return E2-E1;

}
#endif //UNTITLED_ENERGYDIFF_H
