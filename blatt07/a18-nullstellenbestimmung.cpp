/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 18
 * Nullstellenbestimmung
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double epsilonx = 1e-4;
double epsilony = 1e-3;


double searchZeros(double x0, double x1, double epsilonx, double epsilony, 
        double (*func)(double), double (*pivot)(double, double, double (*fnc)(double))) {
    
    // ueberpruefen, ob NST im Intervall
    if((func(x0)*func(x1) > 0)) {
        cout << "Das eingegebene Intervall enthaelt nicht genau eine Nullstelle!" << endl;
        return(0);
    }

    int schritt = 0;
    double xtest;

    do {
        schritt++;
        xtest = pivot(x0, x1, func);

        // ist NST im linken Teilintervall?
        ((func(x0)*func(xtest) >= 0)? x0 : x1) = xtest;
        
        // Ausgabe des aktuellen Schritts
        cout << "n = " << setw(2) << schritt << ": NST in [" << x0 << ", " << x1 << "]. ";
        cout << "Teste: f(" << xtest << ") = " << func(xtest) << endl;

    } while(abs(x1-x0) >= epsilonx && abs(func(xtest)) >= epsilony);

    return(xtest);
}

double pivotBisektion(double x0, double x1, double (*func)(double)) {
    return (x0+x1)/2;
}

double pivotSekante(double x0, double x1, double (*func)(double)) {
    return (x0*func(x1)-x1*func(x0))/(func(x1)-func(x0));
}

double f1(double x) {
    return cos(x) - x;
}

double f2(double x) {
    return exp(x) - pow(x,3);
}


int main() {

    // Zwischenspeicher fuer Nullstelle
    double zero = 0;

    cout << "Teste f1(x) = cos(x) - x:" << endl <<  endl;
    cout << "Bisektionsverfahren:" << endl;
    zero = searchZeros(-10.0, 10.0, 1e-4, 1e-3, &f1, &pivotBisektion);
    cout << endl << "Ergebnis für Nullstelle: " << zero << endl << endl;

    zero = searchZeros(-10.0, 10.0, epsilonx, epsilony, &f1, &pivotSekante);
    cout << endl << "Ergebnis fuer Nullstelle: " << zero << endl << endl;

    cout << "Teste f2(x) = exp(x) - x^3:" << endl << endl;
    cout << "Bisektionsverfahren:" << endl;
    zero = searchZeros(2, 10, epsilonx, epsilony, &f2, &pivotBisektion);
    cout << endl << "Ergebnis fuer Nullstelle: " << zero << endl << endl;

    zero = searchZeros(2, 10, epsilonx, epsilony, &f2, &pivotSekante);
    cout << endl << "Ergebnis fuer Nullstelle: " << zero << endl << endl;

    return(0);
}
