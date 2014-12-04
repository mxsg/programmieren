/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 24 (Zusatz)
 * Rectangle-Klasse
 */

#include <iostream>
#include "Rectangle.hpp"

void Rectangle::setSize(double width, double height) {
    if(width >= 0.0 && height >= 0.0) {
        _width = width;
        _height = height;
    }
}

double Rectangle::area() const {
    return this->width() * this->height();
}

double Rectangle::circumference() const {
    return 2*this->width() + 2*this->height();
}

void Rectangle::rotate() {
    this->setSize(this->height(), this->width());
}

bool Rectangle::covers(Rectangle rect) const {
    return (this->width() >= rect.width() && 
            this->height() >= rect.height());
}

bool Rectangle::coversWithRotation(Rectangle rect) const {
    return (this->covers(rect) || 
            (this->width()>=rect.height() && this->height()>= rect.width()));
}

std::ostream& operator<<(std::ostream &str, const Rectangle &rect) {
    return str << "rect: (width = " << rect.width() << ", height = "
        << rect.height() << ")";
}
