/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 25:
 * rationale Zahlen
 */

#include "Ratio.h"
#include <iostream>

using namespace std;

int main() {

    Ratio result = Ratio(2,25)/Ratio(7,5)-Ratio(2,5)
        * (-Ratio(1,4) + Ratio(1,3));

    cout << "Das Ergebnis ist: " << result << " bzw. "
        << result.doubleValue() << "." << endl;
}
