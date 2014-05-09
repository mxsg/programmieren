/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 10
 * Pi mit der Monte-Carlo-Methode berechnen
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

  // Zufallszahlengenerator mit Zufallsdaten fuettern
  srand((unsigned int)time(0));

  // Variablen deklarieren
  int nTreffer = 0;
  int n = 0;
  double x, y;

  // Anzahl der Durchgaenge abfragen
  cout << "Bitte die Anzahl der Durchgaenge eingeben: ";
  cin >> n;

  for(int i = 0; i < n; i++) {

    x = double(rand())/RAND_MAX;
    y = double(rand())/RAND_MAX;

    if((x*x + y*y) <= 1) {
      nTreffer++;
    }
  }

  double piApprox = nTreffer/double(n) * 4.0;

  // Ergebnis fuer Pi ausgeben
  cout << "Das numerisch ermittelte Ergebnis fuer Pi betraegt: " << piApprox << endl;

  return(0);
}
