/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 16
 * Funktionswerte mithilfe von Polynomen und Stuetzstellen
 * aus Datei interpolieren
 */

#include <iostream>
#include <fstream>

using namespace std;

const int maxPoints = 200;
const string defaultInputFile = "a16-interpol.dat";
const string resultFile = "a16-interpol-res.dat";

int main() {

  string inputFilename;
  
  cout << "Bitte Quelldatei eingeben (Standard: a16-interpol.dat): ";
  getline(cin, inputFilename);

  // falls nichts eingegeben, Standard verwenden
  if(inputFilename.empty()) inputFilename = defaultInputFile;

  ifstream fin(inputFilename);
  if(!fin) {
    cout << "Kann Datei nicht finden!" << endl;
    exit(1);
  }

  // Stuetzstellen
  double xi[maxPoints], fxi[maxPoints];
  int pointCtr = 0;

  cout << "Stuetzstellen:" << endl;

  while(fin >> xi[pointCtr] >> fxi[pointCtr]) {
    // Stuetzstellen ausgeben
    cout << "f(" << xi[pointCtr] << ") = " << fxi[pointCtr] << endl;
    pointCtr++;

    if(!(pointCtr<maxPoints)) {
      cout << "Zu viele Stuetzstellen!" << endl;
      exit(1);
    }
  }
  fin.close();

  // Datenausgabe vorbereiten
  ofstream fout(resultFile);
  if(!fout) {
    cout << "Kann Datei nicht oeffnen!" << endl;
    exit(1);
  }

  double x = 0, fx = 0;
  double lagrProdukt = 1;

  cout << "Bitte Punkte fuer Interpolation eingeben:" << endl << "x = ";

  while(cin >> x && x != 0) {
    fx = 0;

    // Interpolation berechnen
    for(int i = 0; i<pointCtr; i++) {
      lagrProdukt = fxi[i];

      for(int k = 0; k<pointCtr; k++) {
        if(i != k) lagrProdukt *= (x - xi[k])/(xi[i]-xi[k]);
      }
      fx += lagrProdukt;
    }
    
    // berechneten Wert ausgeben und in Datei schreiben
    cout << "f(" << x << ") = " << fx << endl << "x = ";
    fout << x << " " << fx << endl;
  }
  // geschriebene Datei schliessen
  fout.close();
}
