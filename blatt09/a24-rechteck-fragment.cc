/*
 * Programmieren fuer Physiker, SS 2014, Blatt 9, Aufgabe 24
 *
 * Struct fuer Rechteck
 */

#include <iostream>
using namespace std ;

// zu ergaenzen: struct rechteck und Funktionen damit 

int main()
{
    cout << "Rechteckstuct" << endl ;
    rechteck r1 = {3.3, 2.0} ;
    rechteck r2 = {1.8, 2.7} ;
    
    cout << "Vor Rotation: " ;
    if (bedeckt(r1,r2))	cout << "r1 bedeckt r2." ;
    else cout << "r1 bedeckt r2 nicht." ;
    cout << endl ;

    r2 = rotation(r2) ;

    cout << "Nach Rotation: " ;
    if (bedeckt(r1,r2))	cout << "r1 bedeckt r2." ;
    else cout << "r1 bedeckt r2 nicht." ;
    cout << endl ;
}
