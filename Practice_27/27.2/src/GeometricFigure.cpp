#include "GeometricFigure.h"


void GeometricFigure::setCenterX(int velue){
    this->center.x = velue;
}

void GeometricFigure::setCenterY(int velue){
    this->center.y = velue;
}

GeometricFigure::Point GeometricFigure::getCenter() const{
    return this->center;
}

void GeometricFigure::seeColors() {
    cout << "Colors:"
            "\n\t1. Red"
            "\n\t2. Blue"
            "\n\t3. Green" << endl;
}

string GeometricFigure::strColor(){
    if (this->color == Red) return "Red";
    else if (this->color == Blue) return "Blue";
    else if (this->color == Green) return "Green";
    else return "None";
}

void GeometricFigure::setColor(int inColor) {
    this->color = (Color) inColor;
}

GeometricFigure::Color GeometricFigure::getColor() const {
    return this->color;
}

void GeometricFigure::setSquare(double inSquare) {
    this->square = inSquare;
}

double GeometricFigure::getSquare() const {
    return this->square;
}
