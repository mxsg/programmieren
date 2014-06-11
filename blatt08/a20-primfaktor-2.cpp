/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 20
 * Wie oft durch zwei teilbar?
 */

#include <iostream>

using namespace std;

int primeFactorTwo(int value) {

    return (value % 2 != 0 || !value)? 0 : primeFactorTwo(value/2) + 1;
}

int main() {

    // Zahl einlesen
    int value;
    cout << "Bitte eine Zahl eingeben: ";
    cin >> value;

    cout << "Anzahl des Primfaktors 2 bei dieser Zahl: " << primeFactorTwo(value) << endl;

    return 0;
}
