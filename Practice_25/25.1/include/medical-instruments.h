#pragma once

struct point{
    float x = 0;
    float y = 0;
};
struct math_vector{
    point start;
    point end;
    float delta_x;
    float delta_y;
    float length;
};
struct cut{
    math_vector vector;
    point inner_point;
};

void inputPoint (point& p);
void fillMathVector(math_vector& vector);
void scalpel(cut& cut);
void hemostat(cut& cut);
void tweezers(cut& cut);
void suture(cut& cut);