#pragma once
#include <cmath>
#include "GeometricFigure.h"

using namespace std;

class Rectangle: public GeometricFigure {
private:
    double width;
    double length;

public:
    Rectangle(double inWidth, double inLength);

    double getWidth() const;

    double getLength() const;

};
