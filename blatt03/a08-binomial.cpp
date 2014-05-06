/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 8
 * Binomialkoeffizienten ausgeben
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  
  // Felder anlegen
  int zeile[10], zeiletmp[10];

  // Zeilen einzeln berechnen und ausgeben
  for(int n = 0; n < 10; n++) {
    // temoraeres Feld fuellen
    for(int i = 0; i <= n; i++) {
      zeiletmp[i] = zeile[i];
    }

    // erstes, letztes Element setzen
    zeile[0] = 1;
    zeile[n] = 1;

    // Zwischenelemente setzen
    for(int k = 1; k < n; k++) {
      zeile[k] = zeiletmp[k-1] + zeiletmp[k];
    }

    // Zeile ausgeben
    // fuer jede Zahl 4 Zeichen Breite reservieren
    // vor dem ersten Element je nach Zeile Platz frei lassen
    cout <<  setw(40-4*n) << zeile[0];
    for (int j = 1; j <= n; j++) cout << setw(8) << zeile[j] ;
    cout <<  endl;
  }

  return 0;
}
