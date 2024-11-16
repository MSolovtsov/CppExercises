#include "Shape.h"

void printParams(Shape* shape){
    cout << shape->type() << endl;
    cout << "\tSquare = " << shape->square() << " cm^2"<< endl;
    cout << "\tWidth = " << shape->dimensions().width << " cm" << endl;
    cout << "\tHeight = " << shape->dimensions().height << " cm" << endl;

}

int main() {
    cout << "\nTask #2\n  Shape Interface\n" << endl;

    Circle* circle = new Circle(2.5);
    Triangle* triangle = new Triangle(2.4, 6.1, 4.9);
    Rectangle* rectangle = new Rectangle(5.3, 9.4);

    printParams(rectangle);
    printParams(triangle);
    printParams(circle);

    delete circle;
    delete triangle;
    delete rectangle;
    return 0;
}
