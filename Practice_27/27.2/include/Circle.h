#pragma once
#include <cmath>
#include "GeometricFigure.h"

using namespace std;

class Circle: public GeometricFigure {
private:
    double radius;
public:

    Circle(double inRadius);

    double getRadius() const;

};
