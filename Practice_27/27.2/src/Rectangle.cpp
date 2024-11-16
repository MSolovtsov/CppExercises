#include "Rectangle.h"

Rectangle::Rectangle(double width, double length) {
    this->width = width;
    this->length = length;
    setCenterX(ceil(this->width / 2));
    setCenterY(ceil(this->length / 2));

    setSquare(this->length * this->width);
}

double Rectangle::getWidth() const{
    return this->width;
}

double Rectangle::getLength() const{
    return this->length;
}