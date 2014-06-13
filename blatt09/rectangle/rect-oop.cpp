/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 24 (Zusatz)
 * Rectangle-Klasse
 */

#include <iostream>
#include "Rectangle.h"

using namespace std;

int main() {

    cout << "Rechteck-Klasse" << endl;
    Rectangle r1(3.3, 2.0);
    Rectangle r2(1.8, 2.7);
    
    cout << "Vor Rotation: ";
    if(r1.covers(r2)) cout << "r1 bedeckt r2.";
    else cout << "r1 bedeckt r2 nicht.";
    cout << endl;
    
    r2.rotate();
    
    cout << "Nach Rotation: ";
    if(r1.covers(r2)) cout << "r1 bedeckt r2.";
    else cout << "r1 bedeckt r2 nicht.";
    cout << endl;
}
