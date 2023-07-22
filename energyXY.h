//
// Created by kim-jonas on 2023-07-12.
//
#include "math.h"
#ifndef energyXY_H
#define energyXY_H


double energyXY(int gridsize,int couplingconst, double lattice[gridsize][gridsize]){
    int i,j, len = gridsize-1;
    double energy = 0;

    for ( i = 0; i <=len ; ++i) {
        for ( j = 0; j <=len ; ++j) {

            if (i == 0 && j == 0) {
                energy -= couplingconst * (cos(lattice[i][j] - lattice[i][len]) + cos(lattice[i][j] - lattice[len][j]) +
                                           cos(lattice[i][j] - lattice[i + 1][j]) +
                                           cos(lattice[i][j] - lattice[i][j + 1]));
            }
            else if(i == 0 && j == len){
                energy -= couplingconst * (cos(lattice[i][j] - lattice[len][j]) + cos(lattice[i][j]-lattice[i+1][j])
                        + cos(lattice[i][j] - lattice[i][j-1]) + cos(lattice[i][j] - lattice[i][0]));
            }
            else if (i == len && j == 0){
                energy -= couplingconst * (cos(lattice[i][j] - lattice[len-1][j]) + cos(lattice[i][j] - lattice[0][0])
                        + cos(lattice[i][j] - lattice[len][j+1]) + cos(lattice[i][j] - lattice[len][len]));

            }
            else if (i == len && j == len){
                energy -= couplingconst * (cos(lattice[i][j] - lattice[len-1][len]) + cos(lattice[i][j] - lattice[len][len-1])
                        + cos(lattice[i][j] - lattice[0][len]) + cos(lattice[i][j] - lattice[len][0]));
            }
            else if (i == 0){
                energy -= couplingconst * (cos(lattice[i][j] - lattice[len][j]) + cos(lattice[i][j] - lattice[i+1][j])
                        + cos(lattice[i][j]-lattice[i][j+1]) + cos(lattice[i][j]-lattice[i][j-1]));
            }
            else if (i == len){
                energy -= couplingconst * (cos(lattice[i][j] - lattice[i-1][j]) + cos(lattice[i][j] - lattice[0][j])
                        + cos(lattice[i][j] - lattice[i][j-1]) + cos(lattice[i][j] - lattice[i][j+1]));
            }
            else if (j == 0){
                energy -= couplingconst * (cos(lattice[i][j] - lattice[i+1][j]) + cos(lattice[i][j] - lattice[i-1][j])
                        + cos(lattice[i][j] - lattice[i][j+1]) + cos(lattice[i][j]- lattice[i][len]));
            }
            else if (j == len){
                energy -= couplingconst * (cos(lattice[i][j] - lattice[i+1][j]) + cos(lattice[i][j] - lattice[i-1][j])
                        + cos(lattice[i][j] - lattice[i][j-1]) + cos(lattice[i][j] - lattice[i][0]));
            }
            else{
                energy -= couplingconst * (cos(lattice[i][j] - lattice[i-1][j]) + cos(lattice[i][j] - lattice[i+1][j])
                        + cos(lattice[i][j] - lattice[i][j-1]) + cos(lattice[i][j] - lattice[i][j+1]));
            }

            }
        }

    return energy / (gridsize*gridsize);

    }









#endif