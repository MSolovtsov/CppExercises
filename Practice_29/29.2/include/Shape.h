#pragma once
#include <iostream>
#include <cmath>
#define PI 3.14159

using namespace std;


class Shape {
protected:
    double shape_square;

    string shape_type;

    struct BoundingBoxDimensions {
        double width = 0.;
        double height = 0.;
    };

public:
    virtual double square() = 0;

    virtual BoundingBoxDimensions dimensions() = 0;

    virtual string type() = 0;

};



class Circle : virtual public Shape {
private:
    BoundingBoxDimensions circle_dimensions;
public:
    Circle(double _radius);

    virtual double square();

    virtual BoundingBoxDimensions dimensions();

    virtual string type();
};



class Rectangle : virtual public Shape {
private:
    BoundingBoxDimensions rectangle_dimensions;
public:
    Rectangle(double _weight, double _height);

    virtual double square();

    virtual BoundingBoxDimensions dimensions();

    virtual string type();
};



class Triangle : virtual public Shape{
private:
    BoundingBoxDimensions triangle_dimensions;
    double p;
public:
    Triangle(double _side1, double _side2, double _side3);

    virtual double square();

    virtual BoundingBoxDimensions dimensions();

    virtual string type();
};

