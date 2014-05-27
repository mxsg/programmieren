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
  int width = 0, heigth = 0;
  fin >> width >> heigth;

  // mitzaehlen, wie viele des aktuellen Symbols folgen
  int currentSymb;
  int currentSymbCtr = 0;
  int lineCtr = width;

  int remSymb = width*heigth;
  
  // ueber verbleibende Zeichen iterieren
  while(remSymb > 0) { 
    
    // neues Symbol einlesen
    if(!currentSymbCtr) {
      fin >> currentSymb  >> currentSymbCtr;
    }

    if(!lineCtr) {
      cout << "\n";
      lineCtr = width;
    }

    while(currentSymbCtr > 0 && lineCtr > 0) {
      cout << symbols[currentSymb];
      currentSymbCtr--;
      lineCtr--;
      remSymb--;
    }
  }

  return(0);
}
