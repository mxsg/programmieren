/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 4a)
 * Produkt-Berechnung
 */

#include <iostream>

using namespace std;

int main() {
  int N = 0;
  long int result = 1;
  
  // oberen Index einlesen
  cout << "Bitte einen oberen Index eingeben: ";
  cin >> N;

  for(int i = 1; i <= N; i++) {
    result *= (3*i - 1);
  }

  cout << "Das Ergebnis des Produkts betraegt: " << result << endl;

  return(0);
}
