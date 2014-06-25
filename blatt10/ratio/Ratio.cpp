/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 25:
 * rationale Zahlen
 */

#include "Ratio.h"
#include <iostream>

Ratio::Ratio(long a, long b) {

    // catch erroneous inputs
    if(!b) {
        std::cerr << "Error in Ratio initialisation: "
            << "denom==0, set to 1 instead" << std::endl;
        b = 1;
    }
    // flip signs for negative denominator
    if(b < 0) {
        a *= -1; b *= -1;
    }

    _num = a;
    _denom = b;
    reduceRatio(); // always construct reduced ratios
}

void Ratio::reduceRatio() {
    long gcd = greatestCommonDivisor(_num, _denom);
    _num /= gcd;
    _denom /= gcd;
}

long Ratio::greatestCommonDivisor(long a, long b) const {

    // algorithm only works for positive numbers
    a = std::abs(a); b = std::abs(b);

    // use the euclidean algorithm to compute
    // greatest common divisor of a and b
    if(b == 0) return a;
    else return greatestCommonDivisor(b, a % b);
}

long Ratio::leastCommonMultiple(long a, long b) const {

    // algorithm only works for positive numbers
    a = abs(a); b = abs(b);

    return a / greatestCommonDivisor(a, b) * b;
}

double Ratio::doubleValue() const {
    return _num / double(_denom);
}

Ratio Ratio::invert() const {
    return Ratio(_denom, _num);
}

Ratio Ratio::operator+(const Ratio b) const {

    long lcm = leastCommonMultiple(_denom, b._denom);

    // construct new Ratio
    Ratio result = Ratio(lcm/_denom*_num + lcm/b._denom*b._num, lcm);

    return result;
}

Ratio Ratio::operator-() const {
    return Ratio(-_num, _denom);
}

Ratio Ratio::operator-(const Ratio b) const {
    return -b + *this;
}

Ratio Ratio::operator*(const Ratio b) const {
    
    // calculate gcds to avoid overflows
    long gcd1 = greatestCommonDivisor(_num, b._denom);
    long gcd2 = greatestCommonDivisor(_denom, b._num);
    long resNum = (_num/gcd1) * (b._num/gcd2);
    long resDenom = (_denom/gcd2) * (b._denom/gcd1);

    return Ratio(resNum, resDenom);
}

Ratio Ratio::operator/(const Ratio b) const {
    return *this * b.invert();
}

std::ostream& operator<<(std::ostream &str, const Ratio ratio) {

    str << ratio._num;
    if(ratio._denom != 1) str << "/" << ratio._denom;
    return str;
}
