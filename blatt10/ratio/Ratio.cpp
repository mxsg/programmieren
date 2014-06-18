/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 25:
 * rationale Zahlen
 */

#import "Ratio.h"
#import <iostream>

Ratio::Ratio(long a, long b) {

    // catch erroneous inputs
    if(!b) {
        std::cerr << "Error in Ratio initialisation:" << std::endl 
            << "denom==0, set to 1 instead" << std::endl;
        b = 1;
    }

    // flip signs for negative denominator
    if(b < 0) {
        a *= -1; b *= -1;
    }

    _num = a;
    _denom = b;
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

Ratio Ratio::operator+(const Ratio b) {

    long lcm = leastCommonMultiple(_denom, b._denom);

    // construct new Ratio
    Ratio result = Ratio(lcm/_denom*_num + lcm/b._denom*b._num, lcm);

    // reduce result
    result.reduceRatio();

    return result;
}

Ratio Ratio::operator-() const {

    return Ratio(-_num, _denom);
}

Ratio Ratio::operator-(const Ratio b) {
    return -b + *this;
}

Ratio Ratio::operator*(const Ratio b) {
    
    Ratio result = Ratio(_num * b._num, _denom * b._denom);
    result.reduceRatio();
    return result;
}

Ratio Ratio::operator/(const Ratio b) {
    return *this * b.invert();
}

std::ostream& operator<<(std::ostream &str, const Ratio ratio) {
    return str << ratio._num << "/" << ratio._denom;
}
