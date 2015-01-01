/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 24 (Zusatz)
 * Rectangle-Klasse
 */

class Rectangle {

    double _width, _height;

    public:
        Rectangle(double width=0, double height=0) 
            : _width(width), _height(height) {};

        void setSize(double width, double height);
        double width() { return this->_width; };
        double height() { return this->_height; };
        double area();
        double circumference();
        void rotate();
        bool covers(Rectangle rect);
        bool coversWithRotation(Rectangle rect);

    friend std::ostream& operator<<(std::ostream& str, const Rectangle &rect);
};
