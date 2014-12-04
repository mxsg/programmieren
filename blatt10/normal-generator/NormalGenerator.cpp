/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 26:
 * Normalverteilte Zufallszahlen
 */

#include "NormalGenerator.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

NormalGenerator::NormalGenerator(double newMean, double newDeviation) {
    lastNumber = 0.0;
    mean = newMean;
    deviation = newDeviation;
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
    } while(s >= 1 || s==0.0);

    lastNumber = calcNormDistributed(v1, s);
    randLeft = true;

    return calcNormDistributed(v2, s);
}

double NormalGenerator::calcNormDistributed(double v, double s) {
    return deviation*v*sqrt(-2*log(s)/s) + mean;
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
    std::cout << "Generating " << randCount << " random numbers ... " << std::flush;
    for(int i=0; i<randCount; i++) {
        rands.push_back(get());
    }
    std::cout << "done." << std::endl;

    return rands;
}
