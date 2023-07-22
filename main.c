#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "initialcond.h"
#include "energyXY.h"
#include "magnetization.h"
#include "RandomWalkFunction.h"
#include "Energydiff.h"


int main(void) {

    int gridsize, trials, L2;
    double Tmin, Tmax, Tstep;

    printf("Enter the number L (integer) for latticesize LxL: ");
    scanf("%d", &gridsize);
    printf("\n");
    printf("Enter the number of iterations (integer) > 1000000: ");
    scanf("%d", &trials);
    printf("\n");
    printf("Enter Max temperature (double): ");
    scanf("%lf", &Tmax);
    printf("\n");
    printf("Enter the minimum temperature (double): ");
    scanf("%lf", &Tmin);
    printf("\n");
    printf("Specify the stepsize (double): ");
    scanf("%lf", &Tstep);
    printf("\n");



    int Startsample = 7e5, Samplerate = 20, couplingconst = 1;
    int i, j, thinning, NumberOfSamples;
    double En, EnM, EnM2, Mtemp, M, M2 ,M4 , newAngle, p;
    double g, chi, cv, energydiff;
    double lattice[gridsize][gridsize];
    double criticaltemp, criticalmagsuscpt;

    L2 = gridsize*gridsize;

    srand(time(NULL));

    FILE *fp;
    fp = fopen("MCdata.csv","w+");

    if (fp == NULL){
        printf("Failed to open file \n");
        return 1;
    }


    printf("Temp -- Energy -- Magnetism -- Heatcap -- Magsuscept -- Bindercumulant\n");

    for (double t = Tmin; t <= Tmax ; t = t + Tstep) {

        En = EnM = EnM2 = 0;
        M = M2 = M4 = 0;
        NumberOfSamples = 0;
        thinning = 0;

        initialcondition(gridsize, lattice);
        En = energyXY(gridsize, couplingconst, lattice);

        i = (int)rand() % (gridsize); // startindex i - random
        j = (int)rand() % (gridsize); // startindex j - random

        for (int sweep = 0; sweep <= trials; ++sweep) {

            newAngle = 2 * M_PI * (double)rand() / (double)RAND_MAX;
            energydiff = Energydiff(gridsize,lattice,i,j,newAngle,couplingconst); // Find energy for new state.
            p = exp(-energydiff/t);

            if (energydiff <= 0 || (double)rand() / (double)RAND_MAX < p){  // Metropolis-hastings algorithm.

                lattice[i][j] = newAngle;
                //En += 2*energydiff; varfor blir det har fel
                En = energyXY(gridsize, couplingconst, lattice); // Find energy of new state.

            }

            if (sweep > Startsample){ // start measurements

                thinning++;

                if (thinning > Samplerate){

                    Mtemp = magnetization(gridsize, lattice); // Find magnetization of state to be sampled

                    EnM += En;
                    EnM2 += En*En;
                    M += Mtemp;
                    M2 += Mtemp*Mtemp;
                    M4 += Mtemp*Mtemp*Mtemp*Mtemp;

                    thinning = 0;
                    NumberOfSamples++;

                }
            }

            RandomWalkFunction(&i, &j, gridsize); // Random walk around lattice

        }

        EnM = EnM/NumberOfSamples;
        EnM2 = EnM2/NumberOfSamples;
        M = M/NumberOfSamples;
        M2 = M2/NumberOfSamples;
        M4 = M4/NumberOfSamples;

        g = 1 - (M4/(3*M2*M2)); /* binder cummulant */
        chi = (L2) * (M2 - M*M) / t; /* Magnetic susceptibility */
        cv = (EnM2 - EnM*EnM) / (L2*t*t); /* Heatcapacity */

        if (chi > criticalmagsuscpt){
            criticalmagsuscpt = chi;
            criticaltemp = t;
        }
        /* Data printed as: Temp Energy Magnetization Heatcapacity Magnetic-susceptibility binder-cumulant */
        fprintf(fp,"%f, %f, %f, %.10f, %f, %f\n",t,EnM,M,cv,chi,g);

        printf("%f, %f, %f, %f, %.10f, %f\n", t, EnM, M, cv, chi, g); // Prints values in console.


        }
    printf("Critical temperature: %f", criticaltemp); // Critical temperature evaluated from magnetic susceptibility.

    fclose(fp);
    return 0;
}