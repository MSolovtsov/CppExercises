#pragma once
#include <iostream>

using namespace std;

const double PI = 3.14159;

class GeometricFigure {
private:
    enum Color{
        None = 0,
        Red = 1,
        Blue = 2,
        Green = 3
    };

    struct Point{
        int x = 0;
        int y = 0;
    };


    Color color = None;

    Point center;

    double square;

public:

    void setCenterX(int velue);

    void setCenterY(int velue);

    Point getCenter() const;

    void setColor(int inColor);

    Color getColor() const;

    void setSquare(double inSquare);

    double getSquare() const;

    static void seeColors();

    string strColor();
};
