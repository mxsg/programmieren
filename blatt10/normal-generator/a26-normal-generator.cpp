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

double standardDeviation(vector<double> numbers) {
    return standardDeviation(numbers, mean(numbers));
}

double fractionOutsideRange(vector<double> numbers, double center, double radius) {
    double ctr = 0;
    double lowerBound = center - radius;
    double upperBound = center + radius;

    for(vector<double>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        // count elements outside bounds
        if(*it < lowerBound || *it > upperBound) ctr++;
    }

    return ctr/(double)numbers.size();
}


int main() {

    NormalGenerator gen = NormalGenerator();
    int randCount;
    vector<double> rands;
    
    cout << "Number of generated random values: ";
    cin >> randCount;

    cout << endl;
    rands = gen.randomVector(randCount);
    cout << endl;

    double randMean = mean(rands);
    double randstd = standardDeviation(rands, randMean);

    cout << "Mean: " << randMean << endl;
    cout << "Standard Deviation: " << randstd << endl;

    cout << endl;
    rands = gen.randomVector(randCount);
    cout << endl;

    randMean = mean(rands);
    randstd = standardDeviation(rands, randMean);

    cout << "Percentage outside number of deviations:" << endl;
    for(int i=1; i<=3; i++) {
        cout << i << " sigma: "
            << 100*fractionOutsideRange(rands, randMean, i*randstd) << "%" << endl;
    }
}
