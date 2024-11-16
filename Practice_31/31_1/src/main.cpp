#include <iostream>
#include <memory>
#include "SmartPointer.h"

using namespace std;


int main() {
    cout << "\nTask 1\n  Implementation of a smart pointer\n" << endl;

    Toy *ball = new Toy("Ball");

    shared_ptr<Toy> ptr = make_shared<Toy>();

    SmartPointerToy* ptrToy1 = new SmartPointerToy(ball);
    SmartPointerToy* ptrToy2 = new SmartPointerToy(ball);

    cout << ball->getCount();



    return 0;
}