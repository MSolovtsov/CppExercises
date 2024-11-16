#pragma once
#include <cmath>
#include "GeometricFigure.h"

using namespace std;

class Square: public GeometricFigure {
private:
    double side;

public:
    Square(double inSide);

    double getSide();
};
