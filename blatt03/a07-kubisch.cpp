/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 7
 * Kubische Gleichung loesen
 */

#include <iostream>
#include <cmath>

using namespace std;

// reelle dritte Wurzel berechnen, auch fuer neg. Argumente
double cubicroot (double x)
{
    if (x>0) return exp(log(x)/3.0) ;
    if (x<0) return -exp(log(-x)/3.0) ;
    return 0.0 ;
}

int main() {

  // benoetigte Variablen deklarieren
  double a, b, c, d;
  double p, q, D;
  double x1, x2, x3;

  // Anzahl der Lösungen
  int anzahlLsg = 0;
	
  // Koeffizienten des Polynoms abfragen
  cout << "Bitte die Koeffizienten der zu loesenden Gleichung eingeben (a != 0):" << endl;
  cout << "a = "; cin >> a;
  cout << "b = "; cin >> b;
  cout << "c = "; cin >> c;
  cout << "d = "; cin >> d;

  // Diskriminante und Hilfvariablen berechnen
  p = (3*a*c - pow(b,2))/(3*pow(a,2));
  q = (2*pow(b,3))/(27*pow(a,3)) - (b*c)/(3*pow(a,2)) + d/a;
  D = pow(q/2,2) + pow(p/3, 3);

  // Fallunterscheidung nach Anzahl der reellen Lösungen
  if(D > 0) {
    x1 = cubicroot(-q/2+sqrt(D))+cubicroot(-q/2-sqrt(D)) - b/(3*a);
    
    anzahlLsg = 1;

    // Loesung ausgeben
    cout << "Es existiert eine einfache reelle Loesung bei:" << endl;
    cout << "x1 = " << x1 << " (einfach)" << endl;
  } 
  else if(D == 0) {
    
    if (q == 0) {
      x1 = -b/(3*a);

      anzahlLsg = 1;

      cout << "Es existiert eine reelle Lösung bei:" << endl;
      cout << "x1 = " << x1 << " (dreifach)" << endl;
    }
    else {
      x1 = cubicroot(q/2) - b/(3*a);
      x2 = cubicroot(-4*q) - b/(3*a);

      anzahlLsg = 2;

      cout << "Es existieren drei reelle Lösungen:" << endl;
      cout << "x1 = " << x1 << " (zweifach)" << endl;
      cout << "x2 = " << x2 << " (einfach)" << endl;
    }
  } else {
    // drei einfache Nullstellen
    double h = acos(-q/2*sqrt(-27/pow(p,3)));
    double pi = 3.14159265358979323846;

    anzahlLsg = 3;

    x1 = -sqrt(-4*p/3)*cos(h/3+pi/3) - b/(3*a);
    x2 = -sqrt(-4*p/3)*cos(h/3-pi/3) - b/(3*a);
    x3 = sqrt(-4*p/3)*cos(h/3) - b/(3*a);

    cout << "Es existieren drei einfache reelle Lösungen:" << endl;
    cout << "x1 = " << x1 << " (einfach)" << endl;
    cout << "x2 = " << x2 << " (einfach)" << endl;
    cout << "x3 = " << x3 << " (einfach)" << endl;
  }

  cout << endl;
  cout << "Probe (P(x) = a*x^3 + b*x^2 + c*x + d =):" << endl;
  if(anzahlLsg >= 1) cout << "P(x1) = " << (a*pow(x1,3) + b*pow(x1,2) + c*x1 + d) << endl;
  if(anzahlLsg >= 2) cout << "P(x2) = " << (a*pow(x2,3) + b*pow(x2,2) + c*x2 + d) << endl;
  if(anzahlLsg >= 3) cout << "P(x3) = " << (a*pow(x3,3) + b*pow(x3,2) + c*x3 + d) << endl;
  return 0;
}
