/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 6
 * Zaehlen in der Basis 3
 */

#include <iostream>

using namespace std;

int main() {

  int counter = 0;

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      for(int k = 0; k < 3; k++) {

        cout << i << j << k << "[3] = " <<  counter << "[10]" << endl;
        counter++;
      }
    }
  }

  return(0);
}
