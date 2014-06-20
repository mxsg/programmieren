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

    vector<double> rands;
    
    // read in parameters with default values
    int randCount = 1000000; double expMean = 0; double expDeviation = 1;
    cout << "Number of values: "; cin >> randCount;
    cout << "Expected mean: "; cin >> expMean;
    cout << "Expected Deviation: "; cin >> expDeviation;

    NormalGenerator gen = NormalGenerator(expMean, expDeviation);

    rands = gen.randomVector(randCount);
    double randMean = mean(rands);
    double randstd = standardDeviation(rands, randMean);

    cout << "Mean: " << randMean << endl;
    cout << "Standard Deviation: " << randstd << endl;

    rands = gen.randomVector(randCount);

    randMean = mean(rands);
    randstd = standardDeviation(rands, randMean);

    // expected probability for values outside
    // of number of standard deviations (for normal distribution)
    double expOutsideDeviations[] = {100, 31.731, 4.550, 0.269};

    cout << "Percentage outside number of deviations:" << endl;
    for(int i=1; i<=3; i++) {
        cout << i << " sigma: "
            << 100*fractionOutsideRange(rands, randMean, i*randstd) << "%" 
            << " (" << expOutsideDeviations[i] << "% expected)" << endl;
    }
}
