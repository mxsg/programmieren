/*
 * Programmieren fuer Physiker: C++ 
 * SS 2014
 *
 * Aufgabe 17
 * Interpolation mit kubischen Splines
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

const string defaultInputFile = "a16-interpol.dat";
const string resultFile = "a17-result.dat";
const string plotFile = "a17-plot.gp";
const int defaultPlotResolution = 300;

int main() {
    
    // Eingabedatei abfragen, ohne Eingabe Standard verwenden
    string inputFilename;
    cout << "Bitte Quelldatei eingeben [" << defaultInputFile << "]: ";
    getline(cin, inputFilename);
    if(inputFilename.empty()) inputFilename = defaultInputFile;

    ifstream fin(inputFilename);
    if(!fin) {
        cout << "Datei nicht gefunden!" << endl;
        exit(1);
    }

    // Stuetzstellen auslesen
    vector<double> xi, yi;
    cout << "Stuetzstellen: " << endl;

    double tempx, tempy;
    while(fin >> tempx >> tempy) {
       // Stuetzstellen ausgeben
       cout << "f(" << tempx << ") = " << tempy << endl;
       xi.push_back(tempx); 
       yi.push_back(tempy);
    }
    fin.close();

    // Anzahl der Stuetzstellen
    // -1, um Gleichheit zu Indizes aus Aufgabe herzustellen
    int n = xi.size() - 1;

    // kubischen Spline berechnen
    double lambda[n+1], my[n+1], d[n+1], M[n+1];
    for(int j=1; j < n; j++) {
        lambda[j] = (xi[j+1] - xi[j])/(xi[j+1] - xi[j-1]);
        my[j] = (xi[j] - xi[j-1])/(xi[j+1] - xi[j-1]);
        d[j] = 6/(xi[j+1] - xi[j-1])*((yi[j+1] - yi[j])/(xi[j+1] - xi[j])
                - (yi[j]-yi[j-1])/(xi[j]-xi[j-1]));
    }
    // Nebenbedingungen
    my[0] = 0; my[n] = 0; d[0] = 0; d[n] = 0; my[0] = 2;

    // LGS aufloesen
    double f;
    for(int i = 1; i <= n; i++) {
        f = -my[i]/my[i-1];
        my[i] = 2 + f*lambda[i-1];
        d[i] += f*d[i-1];
    }

    M[n] = d[n]/my[n];
    for(int i = n-1; i>=0; i--) {
        M[i] = (d[i]-lambda[i]*M[i+1])/my[i];
    }

    // Koeffizienten berechnen
    double alpha[n+1], beta[n+1], gamma[n+1], delta[n+1];
    for(int j=0; j <= n; j++) {
        alpha[j] = yi[j];
        beta[j] = (yi[j+1]-yi[j])/(xi[j+1]-xi[j])-(2*M[j]+M[j+1])/6*(xi[j+1]-xi[j]);
        gamma[j] = M[j]/2;
        delta[j] = (M[j+1]-M[j])/(6*(xi[j+1]-xi[j]));
    }

    // Datenausgabe
    ofstream fout(resultFile);
    if(!fout) {
        cout << "Kann Datei nicht oeffnen!" << endl;
        exit(1);
    }

    int plotResolution = 0;
    cout << "Wie viele Zwischenwerte sollen berechnet werden [" << defaultPlotResolution << "]?";
    if(!(cin >> noskipws >> plotResolution)) plotResolution = defaultPlotResolution;

    double x, fx; // betrachtete Stelle
    double distab = xi[n] - xi[0]; // Abstand zwischen Randpunkten
    int intv = 0; // aktuell betrachtetes Intervall
    double intdist = 0; // Abstand zum linken Rand d. Intervalls

    for(int k=0; k <= plotResolution; k++) {
       x = xi[0] + k*distab/plotResolution;

       // Intervall finden
       while(x>xi[intv+1]) intv++;

       intdist = x - xi[intv];
       fx = alpha[intv] + beta[intv]*intdist + gamma[intv]*pow(intdist,2)
           + delta[intv]*pow(intdist, 3);
        
       fout << x << " " << fx << endl;
    }
    fout.close();

    cout << "Alle Werte in Datei geschrieben." << endl;

    stringstream stream;
    stream << "gnuplot " << plotFile;
    system(stream.str().c_str());
}
