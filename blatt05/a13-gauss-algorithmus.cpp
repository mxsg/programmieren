/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 13
 * Gleichungssysteme mit dem Gauss-Algorithmus loesen
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const string filenameBase = "a13-lgs";
const string filenameExt = ".dat";

int main() {

  int lgsID = 0;
  cout << "Bitte Nummer der LGS-Datei eingeben: ";
  cin >> lgsID;

  // Dabeinamen zusammenbauen
  stringstream stream;
  stream << filenameBase << lgsID << filenameExt;

  cout << "Lese " << stream.str() << " ..." <<  endl;

  // Datei oeffnen
  ifstream fin(stream.str());
  if(fin == 0) {
    cout << "Datei nicht gefunden!" << endl;
    exit(0);
  }

  // Dimension des LGS auslesen
  int n = 0;
  fin >> n;

  cout << "Dimension des LGS: " << n << endl;

  double koeff[n][n];
  double b[n];

  // Matrixelemente und Loesungsvektor einlesen
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<n; j++) {
      fin >> koeff[i][j];
    }
  }

  for(int i = 0; i<n; i++) fin >> b[i];

  // LGS anzeigen
  for(int i = 0; i<n; i++) {
    double z;
    for(int j = 0; j<(n-1); j++) {
      z = koeff[i][j];
      cout << (z<0 ? "(" :"") << z << (z<0 ? ")" :"") << "*x" << j << " + ";
    }
    z = koeff[i][n];
    cout << (z<0 ? "(" :"") << z << (z<0 ? ")" :"") << "*x" << n;
    cout <<  " = " << b[i] << endl;
  }

  // nach Spaltenpivotisierung fragen
  char pivot;
  while(pivot != 'y' && pivot != 'n') {
    cout << "Spaltenpivotisierung durchfuehren? (y/n) ";
    cin >> pivot;
  }

  cout << "Pivotisierung wird" << (pivot == 'n'? " nicht" : "") << " durchgefuert." << endl; 

  return 0;
}
