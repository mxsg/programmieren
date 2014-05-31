/*
 * Programmieren für Physiker: C++
 * SS 2014
 *
 * Selbstbeschreibende Folge
 */

#include <iostream>
#include <vector>

using namespace std;

int computeTerm(unsigned int n) {

    vector<unsigned int> gliederAnz;
    gliederAnz.push_back(0);
    gliederAnz.push_back(1);
    gliederAnz.push_back(3);

    // Sonderfaelle abfangen
    if(n <= 2) return n;

    unsigned int counter;

    while(gliederAnz.back() < n) {

        // naechste Anzahl bestimmen
        counter = gliederAnz.size();
        unsigned int anzahl = 0;
        
        while(gliederAnz[anzahl] < counter) anzahl++;
        
        gliederAnz.push_back(gliederAnz.back() + anzahl);
    }
    return gliederAnz.size() - 1;
}

void printComputation(unsigned int n) {
    cout << "Berechne Wert für n = " << n << " ..." << endl;
    unsigned int result = computeTerm(n);
    cout << "Berechneter Wert: an = " << result << endl;
}

int main() {

    printComputation(1e5);
    cout << endl;
    printComputation(1e6);
    cout << endl;
    printComputation(1e7);
    cout << endl;
    printComputation(1e8);
    cout << endl;
    printComputation(1e9);
}
