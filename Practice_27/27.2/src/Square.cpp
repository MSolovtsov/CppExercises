#include "Square.h"

Square::Square(double inSide){
    this->side = inSide;
    setCenterX(ceil(this->side / 2));
    setCenterY(ceil(this->side / 2));

    setSquare(pow(this->side, 2));
}

double Square::getSide(){
    return this->side;
}