#include "medical-instruments.h"
#include <iostream>
#include <cmath>

using namespace std;

void inputPoint (point& p){
    cout << "\tx:";
    cin >> p.x;
    cout << "\ty:";
    cin >> p.y;
}

void fillMathVector(math_vector& vector){
    vector.delta_x = vector.end.x - vector.start.x;
    vector.delta_y = vector.end.y - vector.start.y;
    vector.length = (float)sqrt(pow(vector.delta_x, 2) + pow(vector.delta_y, 2));
}

bool isInnerPoint(cut& cut){
    float tan_alfa = (cut.vector.delta_y / cut.vector.delta_x);

    if (cut.vector.end.x >= cut.inner_point.x &&
            cut.vector.start.x <= cut.inner_point.x &&
            cut.vector.end.y >= cut.inner_point.y &&
            cut.vector.start.y <= cut.inner_point.y)
        if ((cut.inner_point.y - cut.vector.start.y) / (cut.inner_point.x - cut.vector.start.x) == tan_alfa)
            return true;

    return false;
}

void scalpel(cut& cut){
    cout << "Make a cut from" << endl;
    inputPoint(cut.vector.start);
    cout << "before" << endl;
    inputPoint(cut.vector.end);
    fillMathVector(cut.vector);
    cout << "An incision was made at the [" << cut.vector.delta_x << "; " << cut.vector.delta_y << "]" << endl;
    cout << "-----------------------------------" << endl;
}

void take_one_point_on_the_cut(cut& cut){
    bool next;
    do {
        inputPoint(cut.inner_point);
        next = isInnerPoint(cut);
        if (!next) cout << "out of range!\n";
    } while(!next);
}


void hemostat(cut& cut){
    cout << "Make a clamp" << endl;
    take_one_point_on_the_cut(cut);
    cout << "-----------------------------------" << endl;
}

void tweezers(cut& cut){
    cout << "Work with tweezers" << endl;
    take_one_point_on_the_cut(cut);
    cout << "Point has been chosen (" << cut.inner_point.x << "; " << cut.inner_point.y << ")" << endl;
    cout << "-----------------------------------" << endl;
}

void suture(cut& cut){
    cout << "Making a seam [" << cut.vector.delta_x << "; " << cut.vector.delta_y << "]" << endl;
    cout << "Operation went well. Congratulations!" << endl;
}