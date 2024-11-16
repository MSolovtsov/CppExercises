#include "Triangle.h"

Triangle::Triangle(double inSide){
    this->side = inSide;
    setCenterX(ceil(this->side / 2));
    setCenterY(ceil((this->side / 2) / sin(PI / 6)));

    setSquare(0.5 * pow(this->side, 2) * cos(PI / 6));
}

double Triangle::getSide(){
    return this->side;
}