/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 24 (Zusatz)
 * Rectangle-Klasse
 */

#include <iostream>
#include "Rectangle.h"

//using namespace std;

int main() {

    std::cout << "Rechteck-Klasse" << std::endl;
    Rectangle r1(3.3, 2.0);
    Rectangle r2(1.8, 2.7);
    
    std::cout << "Vor Rotation: ";
    if(r1.covers(r2)) std::cout << "r1 bedeckt r2.";
    else std::cout << "r1 bedeckt r2 nicht.";
    std::cout << std::endl;
    
    r2.rotate();
    
    std::cout << "Nach Rotation: ";
    if(r1.covers(r2)) std::cout << "r1 bedeckt r2.";
    else std::cout << "r1 bedeckt r2 nicht.";
    std::cout << std::endl;
}
