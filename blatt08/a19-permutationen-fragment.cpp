/*
 * Programmieren fuer Physiker, SS 2014, Blatt 8, Aufgabe 19
 *
 * Permutationen in lexikographischer Ordnung generieren
 * (Fragment, zu ergaenzen)
 */

#include <iostream>
using namespace std ;

// die Funktionen next_permutation (und swap) sind zu ergaenzen

int main()
{
    // Beispieldatensatz, muss sortiert vorliegen
    const int size=6 ;
    char wort[size] = {'A','E','E','F','F','K'} ;

    cout << "Generierung aller Permutationen" << endl << endl ;

    // Hauptschleife, erzeuge alle Permutationen
    int anzperm = 0 ;      // zaehle die Permutationen
    do
    {
	++anzperm ;
	cout << "Nr: " << anzperm << "  " ;
	for( int i=0; i<size; i++)
	    cout << wort[i] << " " ;
	cout << endl ;
    }
    while (next_permutation(wort, size))  ;

    cout << "Anzahl der Permutationen: " << anzperm << endl ;
}
