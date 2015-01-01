/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 26:
 * Normalverteilte Zufallszahlen
 */

#include "NormalGenerator.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

NormalGenerator::NormalGenerator() {
    lastNumber = 0.0;
    randLeft = false;

    // initialize PRNG
    srand((unsigned int)time(0));
}

double NormalGenerator::generateRandomNumbers() {

    double v1, v2;
    double s;

    do {
        v1 = 2.0*(rand()/(double)RAND_MAX) - 1;
        v2 = 2.0*(rand()/(double)RAND_MAX) - 1;
        s = pow(v1,2) + pow(v2,2);
    } while(s >= 1 || s==0);

    lastNumber = v1*sqrt(-2*log(s)/s);
    randLeft = true;

    return v2*sqrt(-2*log(s)/s);
}

double NormalGenerator::get() {

    if(randLeft) {
        randLeft = false;
        return lastNumber;
    } else {
        return generateRandomNumbers();
    }
}

std::vector<double> NormalGenerator::randomVector(int randCount) {

    std::vector<double> rands;
    std::cout << "Generating " << randCount << " random numbers ..." << std::endl;
    for(int i=0; i<randCount; i++) {
        rands.push_back(get());
    }

    return rands;
}
