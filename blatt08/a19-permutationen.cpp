/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 19
 * Permutationen in lexikographischer Ordnung generieren
 */

#include <iostream>
#include <iomanip>

using namespace std;

void swapCharValues(char &x, char &y) {
    char temp = x;
    x = y;
    y = temp;
}

bool next_permutation(char word[], int length) {

    // P1: Finde groesstes k mit a_k < a_k+1
    int k = length - 2;
    int l = length - 1;

    while(k >= 0 && !(word[k] < word[k+1])) k--;
    if(k < 0) return false; // alle Permutationen erzeugt

    // P2: Finde groesstes l mit a_k < a_l
    while(!(word[k] < word[l])) l--;

    // P3: Tausche a_k und a_l
    swapCharValues(word[k], word[l]);

    // P4: Drehe die Reihenfolge aller Elemente zwischen k+1 und n um
    for(int i = 1; i <= (length-1-k)/2; i++) {
        swapCharValues(word[k+i], word[length-i]);
    }

    // Permutation wurde erzeugt
    return true;
}

int main() {

    // Beispieldatensatz, muss sortiert vorliegen
    const int size = 6;
    char wort[size] = {'A','E','E','F','F','K'};

    cout << "Generierung aller Permutationen" << endl << endl;

    // Hauptschleife, erzeuge alle Permutationen
    int anzperm = 0;      // zaehle die Permutationen

    do {
	    ++anzperm;
	    cout << "Nr: " << setw(4) << anzperm << "  ";
	    for(int i=0; i<size; i++)
	        cout << wort[i] << " ";
	    cout << endl;
    } while (next_permutation(wort, size));

    cout << "Anzahl der Permutationen: " << anzperm << endl;
}
