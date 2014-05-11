/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Ergebnisse eines Weitsprung-Wettbewerbs
 * einlesen und auswerten
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int teilnehmerzahl = 8;
const int sprungzahl = 6;

int main() {

  // Felder fuer Teilnehmernummern und Sprungweiten erstellen
  int teilnehmer[teilnehmerzahl];
  // erster Index fuer Teilnehmer, zweiter Versuch
  double sprungweiten[teilnehmerzahl][sprungzahl];
  // Bestweiten pro Teilnehmer
  double bestweiten[teilnehmerzahl];
  // gesamte Bestweite
  double rekord = 0;

  // Datei oeffnen
  ifstream fin("a11-weitsprung.dat");
  if(fin == 0) {
    cout << "Datei nicht gefunden!" << endl;
    exit(1);
  }

  // Daten aus Datei einlesen
  // und Bestweite bestimmen
  for(int i = 0; i < teilnehmerzahl; i++) {
    // Teilnehmernummer auslesen
    fin >> teilnehmer[i];

    bestweiten[i] = 0;
    
    // Sprungweiten auslesen
    for(int j = 0; j < sprungzahl; j++) {
      fin >> sprungweiten[i][j];

      bestweiten[i] = (sprungweiten[i][j] > bestweiten[i]) ? 
        sprungweiten[i][j] : bestweiten[i];
    }

    rekord = (bestweiten[i] > rekord) ? bestweiten[i] : rekord;
  }
  
  // Ausgabe
  cout << "Nr.   |  Spruenge" << setw(42) << "|  Bestweite  " << endl;
  
  for(int i = 0; i < teilnehmerzahl; i++) {
    cout << setw(4) << teilnehmer[i] << "  |  ";
    
    for(int j = 0; j < sprungzahl; j++) {
      cout << setw(4) << setprecision(2) << fixed <<  sprungweiten[i][j] << "  ";
    }
    cout << "|  " << setw(4) << setprecision(2) << fixed << bestweiten[i] << "  |  ";
    
    if (bestweiten[i] == rekord) cout << "Sieger!";
    cout << endl;
  }
  
  return(0);
}
