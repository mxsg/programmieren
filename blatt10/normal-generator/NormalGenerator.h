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
        double lastNumber;
        bool randLeft;

        double generateRandomNumbers();

    public:
        NormalGenerator();

        double get();
        std::vector<double> randomVector(int randCount);
};
