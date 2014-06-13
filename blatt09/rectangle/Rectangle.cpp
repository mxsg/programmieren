/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 24 (Zusatz)
 * Rectangle-Klasse
 */

#include "Rectangle.h"

void Rectangle::setSize(double width, double height) {
    if(width >= 0.0 && height >= 0.0) {
        this->_width = width;
        this->_height = height;
    }
}

double Rectangle::area() {
    return this->width() * this->height();
}

double Rectangle::circumference() {
    return 2*this->width() + 2*this->height();
}

void Rectangle::rotate() {
    this->setSize(this->height(), this->width());
}

bool Rectangle::covers(Rectangle rect) {
    return (this->width() >= rect.width() && 
            this->height() >= rect.height());
}

bool Rectangle::coversWithRotation(Rectangle rect) {
    return (this->covers(rect) || 
            (this->width()>=rect.height() && this->height()>= rect.width()));
}
