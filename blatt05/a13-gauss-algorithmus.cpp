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
#include <iomanip>
#include <cmath>

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
    exit(1);
  }

  // Dimension des LGS auslesen
  int n = 0;
  fin >> n;

  if(!n) {
    cout << "Fehler beim Lesen der Dimension!" << endl;
    exit(1);
  }

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
    for(int j = 0; j<n; j++) {
      cout << setprecision(3) << setw(8) << koeff[i][j] << " ";
    }
    cout << "| " << setw(9) << b[i] << endl;
  }

  // nach Spaltenpivotisierung fragen
  char pivotAntw;
  cout << "Spaltenpivotisierung durchfuehren? (y/n) ";
  cin >> pivotAntw;
  bool pivot = (pivotAntw == 'y' || pivotAntw == 'Y');

  cout << "Pivotisierung wird" << (pivot? "" : " nicht") << " durchgefuert." << endl; 

  // Dreiecksform bestimmen
  for(int i = 0; i<n; i++) {
    
    // Pivotisierung durchfuehren
    if(pivot) {
      int indexMax = i;
      for(int j = i+1; j<n; j++) {
        // betragsmaessig groesstes Element bestimmen
        if(fabs(koeff[j][i]) > fabs(koeff[indexMax][i])) indexMax = j;
      }

      // i-te und indexMax-te Zeile tauschen
      double temp;
      for(int j = 0; j<n; j++) {
        temp = koeff[i][j];
        koeff[i][j] = koeff[indexMax][j];
        koeff[indexMax][j] = temp;
      }
      temp = b[i];
      b[i] = b[indexMax];
      b[indexMax] = temp;
    }

    double ratio; 
    // Nulleintraege generieren
    for(int j = i+1; j<n; j++) {
      ratio = -(koeff[j][i]/koeff[i][i]);

      // ganze Zeile aufaddieren
      for(int k = i; k<n; k++) {
        koeff[j][k] += ratio * koeff[i][k];
      }
      b[j] += ratio * b[i];
    }
  }
  
  // Rueckwaertsaufloesen
  double x[n]; // Loesungsvektor
  // x[i] mit i-ter Zeile bestimmen
  for(int i = n-1; i>= 0; i--) {
    x[i] = b[i];
    for(int j = n-1; j>i; j--) {
      x[i] -= koeff[i][j] * x[j];
    }
    // endgueltiges x[i] bestimmen
    x[i] /= koeff[i][i];
  }

  // Loesungsvektor ausgeben
  cout << "Loesungsvektor:" << endl;
  cout << "x = ( ";
  for(int i=0; i<n; i++) {
    // Trenner nur zwischen Eintraegen ausgeben
    cout << (i==0 ? "" : ", ");
    cout << setprecision(3) << x[i];
  }
  cout << " )^T" << endl;
  
  return 0;
}
