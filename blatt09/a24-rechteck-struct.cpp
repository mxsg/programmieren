/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 24:
 * Rechteck-Struct
 */

#include <iostream>

using namespace std;

struct rechteck {
    double breite;
    double hoehe;
};

rechteck rotiere(rechteck x) {
    rechteck result = {x.hoehe, x.breite};
    return result;
}

bool bedeckt(rechteck x, rechteck y) {
    return (x.breite >= y.breite && x.hoehe >= y.hoehe);
}

int main() {
    
    cout << "Rechteck-Struct" << endl;
    rechteck r1 = {3.3, 2.0};
    rechteck r2 = {1.8, 2.7};
    
    cout << "Vor Rotation: ";
    if(bedeckt(r1,r2)) cout << "r1 bedeckt r2.";
    else cout << "r1 bedeckt r2 nicht.";
    cout << endl;
    
    r2 = rotiere(r2);
    
    cout << "Nach Rotation: ";
    if(bedeckt(r1,r2)) cout << "r1 bedeckt r2.";
    else cout << "r1 bedeckt r2 nicht.";
    cout << endl;
}
