/*
 * Programmiern fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 26:
 * Normalverteilte Zufallszahlen
 */

#include <vector>

class NormalGenerator {

    private:
        double mean, deviation;
        double lastNumber;
        bool randLeft;

        double generateRandomNumbers();
        double calcNormDistributed(double v, double s);

    public:
        NormalGenerator(double newMean=0, double newDeviation=1);

        double get();
        std::vector<double> randomVector(int randCount);
};
