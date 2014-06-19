/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Zum Knobeln:
 * Zahlen in Summanden zerlegen
 */

#include <iostream>

using namespace std;

long summandNumber(long number, long lowerBound=1) {

    if(number<=0 || lowerBound>number) return 0;

    long result = 0;

    for(long i=lowerBound; i<=number; i++) {
        result += summandNumber(number-i, i);
    }

    return result + 1;
}

int main() {

    cout << "Bitte eine Zahl eingeben: ";
    int number = 0;
    cin >> number;

    cout << "Anzahl der Moeglichkeiten: " << summandNumber(number) << endl;
}
