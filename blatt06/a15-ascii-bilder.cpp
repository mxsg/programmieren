/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 15
 * ASCII-Bilder darstellen
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const char symbols[]  = {'.', ',', '~', '=', '+', ':', '?', '$', '7', '8', 'D', 'I', 'M', 'N', 'O', 'Z'};

const string fileBase = "a15-bild";
const string fileExt = ".dat";

int main() {

  // Bild-Nr. einlesen
  string bildID = "";
  cout << "Welches Bild (Nummer) soll dargestellt werden? ";
  cin >> bildID;

  // Dateinamen zusammenbauen
  stringstream stream;
  stream << fileBase << bildID << fileExt;

  cout << "Lese Datei " << stream.str() << " ..." << endl;

  // Datei oeffnen
  ifstream fin;
  fin.open(stream.str());
  if(fin == 0) {
    cout << "Datei nicht gefunden!" << endl;
    exit(1);
  }

  // Abmessungen des Bilds auslesen
  int width = 0, height = 0;
  fin >> width >> height;

  // aktuelles Symbol und verbleibende Anzahl
  int currentSymb;
  int currentSymbCtr = 0;

  // ueber Zeilen und Spalten iterieren
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {

      if(!currentSymbCtr) fin >> currentSymb >> currentSymbCtr;

      cout << symbols[currentSymb];
      currentSymbCtr--;
    }
    cout << "\n";
  }

  return(0);
}
