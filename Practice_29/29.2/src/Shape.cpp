#include "Shape.h"


//---------Circle------------------------

Circle::Circle(double _radius){
    this->shape_type = "Circle";
    circle_dimensions.width = _radius;
    //circle_dimensions.height = _radius;
    this->shape_square = pow(PI, 2) * circle_dimensions.width;
}
double Circle::square() {
    return this->shape_square;
}
Shape::BoundingBoxDimensions Circle::dimensions(){
    return circle_dimensions;
}
string Circle::type(){
    return this->shape_type;
}



//---------Rectangle------------------------

Rectangle::Rectangle(double _weight, double _height){
    this->shape_type = "Rectangle";
    rectangle_dimensions.width = _weight;
    rectangle_dimensions.height = _height;
    this->shape_square = rectangle_dimensions.height * rectangle_dimensions.width;
}
double Rectangle::square() {
    return this->shape_square;
}
Shape::BoundingBoxDimensions Rectangle::dimensions(){
    return rectangle_dimensions;
}
string Rectangle::type(){
    return this->shape_type;
}



//---------Triangle------------------------

Triangle::Triangle(double _side1, double _side2, double _side3){
    this->shape_type = "Triangle";
    this->p = (_side1 + _side2 + _side3) / 2;
    triangle_dimensions.width = (_side1 > _side2 ? (_side1 > _side3 ? _side1 : _side3) : (_side2 > _side3 ? _side2 : _side3));
    triangle_dimensions.height = (2 / triangle_dimensions.width) * sqrt(this->p * (this->p - _side1)* (this->p - _side2)* (this->p - _side3));
    this->shape_square = triangle_dimensions.height * triangle_dimensions.width / 2;
}
double Triangle::square() {
    return this->shape_square;
}
Shape::BoundingBoxDimensions Triangle::dimensions(){
    return triangle_dimensions;
}
string Triangle::type(){
    return this->shape_type;
}

