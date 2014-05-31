/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 3
 * Berechnung des Osterdatums
 */

#include <iostream>

using namespace std;

int main() {
	
	// fuer den Algorithmus noetige Variablen deklarieren
	int jahr, a, b, c, k, p, q, M, N, d, e;
	int ostertag, ostermonat;
	
	// Jahreszahl einlesen
	cout << "Bitte eine Jahreszahl eingeben: ";
	cin >> jahr;
	
	// Algorithmus vom Aufgabenblatt
	a = jahr % 19;
	b = jahr % 4;
	c = jahr % 7;
	k = jahr / 100;
	p = (8*k + 13) / 25;
	q = k / 4;
	M = (15 + k - p - q) % 30;
	N = (4 + k - q) % 7;
	d = (19 * a + M) % 30;
	e = (2 * b + 4 * c + 6 * d + N) % 7;
	ostertag = 1 + (21 + d + e) % 31;
	ostermonat = 3 + (21 + d + e) / 31;

	// Ergebnis ausgeben als vollstaendiges Datum
	cout << "Ostersonntag ist im angegebenen Jahr am " << ostertag << ".";
	cout << ostermonat << "." << jahr << "." << endl;

	return(0);
}
