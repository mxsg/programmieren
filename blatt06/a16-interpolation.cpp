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
#include <sstream>
#include <vector>

using namespace std;

const string defaultInputFile = "a16-interpol.dat";
const string resultFile = "a16-interpol-res.dat";
const string plotFile = "a16-plot.gp";

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
  vector <double> xi, fxi;

  cout << "Stuetzstellen:" << endl;

  double tempx, tempy;
  while(fin >> tempx >> tempy) {
    // Stuetzstellen ausgeben
    cout << "f(" << tempx << ") = " << tempy << endl;
    xi.push_back(tempx);
    fxi.push_back(tempy);
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
    for(int i = 0; i<xi.size(); i++) {
      lagrProdukt = fxi[i];

      for(int k = 0; k<xi.size(); k++) {
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

  // Plot generieren
  stringstream stream;
  stream << "gnuplot " << plotFile;
  system(stream.str().c_str());
}
