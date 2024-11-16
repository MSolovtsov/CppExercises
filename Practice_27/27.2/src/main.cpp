#include <iostream>
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"

using namespace std;

enum figure{
    Circle_t = 1,
    Square_t = 2,
    Triangle_t = 3,
    Rectangle_t = 4
};

figure figureSelection(){
    cout << "Figure selection:" << endl;
    cout << "\t1. Circle.\n"
            "\t2. Square\n"
            "\t3. Triangle\n"
            "\t4. Rectangle" << endl;
    cout << "figure numbeer:";
    int selectoin;
    do {
        cin >> selectoin;
        if (selectoin > 4 || selectoin < 1) cout << "\tincorrect!\nTry again:";
    } while (selectoin > 4 || selectoin < 1);

    return (figure)selectoin;
}

string strFigure(figure type){
    if (type == Circle_t) return "Circle";
    else if (type == Square_t) return "Square";
    else if (type == Triangle_t) return "Triangle";
    else return "Rectangle";
}

int figureColor(){
    GeometricFigure::seeColors();
    cout << "Your color:";
    int color;
    cin >> color;
    return color;
}

double setSide(bool isMain = true){
    cout << "enter " << ((isMain) ? "main" : "secondary") << " side:";
    double side;
    cin >> side;
    return fabs(side);
}

void print(double square, figure type){
    cout << "\n" << square << " is " << strFigure(type) << " square!" << endl;
    cout << "And color is ";
}

int main() {
    cout << "\nTask #2\n  Hierarchy of geometric shapes\n" << endl;

    figure geomFigure;
    geomFigure = figureSelection();
    if (geomFigure == Circle_t) {

        Circle *circle_class = new Circle(setSide());
        circle_class->setColor(figureColor());
        print(circle_class->getSquare(), geomFigure);
        cout << circle_class->strColor() << "." << endl;
        delete circle_class;

    } else if (geomFigure == Square_t) {

        Square *square_class = new Square(setSide());
        square_class->setColor(figureColor());
        print(square_class->getSquare(), geomFigure);
        cout << square_class->strColor() << "." << endl;
        delete square_class;

    } else if (geomFigure == Triangle_t) {

        Triangle *triangle_class = new Triangle(setSide());
        triangle_class->setColor(figureColor());
        print(triangle_class->getSquare(), geomFigure);
        cout << triangle_class->strColor() << "." << endl;
        delete triangle_class;

    } else {

        Rectangle *rectangle_class = new Rectangle(setSide(), setSide(false));
        rectangle_class->setColor(figureColor());
        print(rectangle_class->getSquare(), geomFigure);
        cout << rectangle_class->strColor() << "." << endl;
        delete rectangle_class;

    }

    return 0;
}
