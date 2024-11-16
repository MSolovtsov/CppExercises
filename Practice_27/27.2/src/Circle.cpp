#include "Circle.h"

Circle::Circle(double inRadius){
    this->radius = inRadius;
    setCenterX(ceil(this->radius));
    setCenterY(ceil(this->radius));

    setSquare( PI * pow(this->radius, 2));
}

double Circle::getRadius() const{
    return this->radius;
}
