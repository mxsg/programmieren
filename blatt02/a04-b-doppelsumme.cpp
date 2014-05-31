/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 4b)
 * Berechnung einer Doppelsumme
 */

#include <iostream>

using namespace std;

int main() {
  int N = 0;
  double result = 0;

  cout << "Bitte einen oberen Index eingeben: ";
  cin >> N;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= i; j++) {

      result += 1/(double)(i*j);
    }
  }

  cout << "Das Ergebnis der Doppelsumme betraegt: " << result << endl;

  return(0);
}
