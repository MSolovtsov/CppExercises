#pragma once
#include <cmath>
#include "GeometricFigure.h"

class Triangle: public GeometricFigure {
private:
    double side;
public:

    Triangle(double inSide);

    double getSide();
};

