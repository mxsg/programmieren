/*
 * Programmieren für Physiker: C++
 * SS 2014
 *
 * Selbstbeschreibende Folge
 */

#include <iostream>
#include <vector>

using namespace std;

struct termRange {
    int term;
    int high;
};

int computeTerm(int n) {

    vector<termRange> gliederAnz;
    termRange temp;
    temp.term = 0; temp.high = 0;
    gliederAnz.push_back(temp);
    temp.term = 1; temp.high = 1;
    gliederAnz.push_back(temp);
    temp.term = 2; temp.high = 3;
    gliederAnz.push_back(temp);

    if(n<=0) return -1;
    if(n==1) return 1;
    if(n==2) return 2;

    int counter = 2;
    int maxCtr = 3;

    while(gliederAnz.back().high < n) {

        counter = gliederAnz.back().term + 1;
        // naechste Anzahl bestimmen
        int anzahl = 0;
        while(gliederAnz[anzahl].high < counter) anzahl++;
        termRange newTerm;
        newTerm.term = counter; newTerm.high = gliederAnz.back().high + anzahl;
        gliederAnz.push_back(newTerm);
    }
    return gliederAnz.back().term;
}

void printComputation(int n) {
    cout << "Berechne Wert für n = " << n << " ..." << endl;
    int result = computeTerm(n);
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
