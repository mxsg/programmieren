/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 * 
 * Aufgabe 5
 * Genauigkeitstest
 */

#include <iostream>

using namespace std;

int main() {

  double epsilon = 1.0;

  while ((1.0 + epsilon) != 1.0) {
    epsilon /= 2;
  }

  cout << "Noch unterscheidbare Differenz mit Datentyp double: "  <<  (2 * epsilon) << endl;

  return(0);
}
