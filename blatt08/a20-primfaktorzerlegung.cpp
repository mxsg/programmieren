/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 20 (Zusatz)
 * Primfaktorzerlegung von Zahlen bestimmen
 */

#include <iostream>
#include <iomanip>

using namespace std;

int factorCount(int number, int factor) {

    return (number % factor == 0)? factorCount(number/factor, factor)+1 : 0;
}

int nextPrime(int lowerBound) {

    int currentNo = lowerBound + 1;

    while(true) {
        for(int i = 2; i < currentNo/2; i++) {
            if(currentNo % i == 0) {
               currentNo++;
               continue;
            }
        }
        return currentNo;
    }
}

void printPrimeDecomposition(int number) {

    int currPrime = 1;
    int currFactorCount = 0;
    int primeFactorCount = 0;

    while(number > 1) {
        currPrime = nextPrime(currPrime);
        int currFactorCount = factorCount(number, currPrime);

        if(currFactorCount) {
            primeFactorCount += currFactorCount;
            cout << "Primfaktor: " << setw(5) << currPrime
                << " ** " << setw(3) << currFactorCount << endl;

            for(int i = currFactorCount; i>0; i--) {
                number /= currPrime;
            }
        }
    }

    // print number of prime factors
    cout << "Anzahl Primfaktoren: " << primeFactorCount << endl;
}


int main() {

    int number;

    // Zahl einlesen
    cout << "Bitte eine zu zerlegende Zahl eingeben: ";
    cin >> number;

    // Primfaktorzerlegung ausgeben
    printPrimeDecomposition(number);
}
