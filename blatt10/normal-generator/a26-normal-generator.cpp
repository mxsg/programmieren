/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 26:
 * Normalverteilte Zufallszahlen
 */

#include "NormalGenerator.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double mean(vector<double> numbers) {
    double result;

    for(vector<double>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        result += *it;
    }

    return result / numbers.size();
}

double standardDeviation(vector<double> numbers, double mean) {
    double result;
    int size = numbers.size();

    for(vector<double>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        result += pow(*it - mean, 2);
    }

    return sqrt(result/size);
}

double fractionOutsideRange(vector<double> numbers, double mean, double diff) {
    double ctr = 0;
    double lowerBound = mean - diff;
    double upperBound = mean + diff;

    for(vector<double>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        if(*it < lowerBound || *it > upperBound) ctr++;
    }

    return ctr/(double)numbers.size();
}

int main() {

    NormalGenerator gen = NormalGenerator();

    vector<double> rands;

    cout << "Generating random numbers ..." << endl;

    for(int i=0; i<1000000; i++) {
        rands.push_back(gen.get());
    }

    double randMean = mean(rands);
    double randStandardDeviation = standardDeviation(rands, randMean);

    cout << "Mean: " << randMean << endl;
    cout << "Standard Deviation: " << randStandardDeviation << endl;

    cout << endl << "Generating random numbers ..." << endl;

    rands.clear();

    for(int i=0; i<1000000; i++) {
        rands.push_back(gen.get());
    }

    randMean = mean(rands);
    double randsd = standardDeviation(rands, randMean);

    cout << "Fractions outside No. of Deviations:" << endl;
    cout << "1 sigma: " << fractionOutsideRange(rands, randMean, randsd) << endl;
    cout << "2 sigma: " << fractionOutsideRange(rands, randMean, 2*randsd) << endl;
    cout << "3 sigma: " << fractionOutsideRange(rands, randMean, 3*randsd) << endl;
}
