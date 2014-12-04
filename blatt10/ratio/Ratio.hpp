/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 25:
 * rationale Zahlen
 */

#include <iostream>

class Ratio {

    private:
        long _num, _denom;
        void reduceRatio();
        long greatestCommonDivisor(long a, long b) const;
        long leastCommonMultiple(long a, long b) const;

    public:
        Ratio(long a=0, long b=1);

        double doubleValue() const;
        Ratio invert() const;

        Ratio operator-() const;
        Ratio operator+(const Ratio b) const;
        Ratio operator-(const Ratio b) const;
        Ratio operator*(const Ratio b) const;
        Ratio operator/(const Ratio b) const;

    friend std::ostream& operator<<(std::ostream &str, const Ratio ratio);
};
