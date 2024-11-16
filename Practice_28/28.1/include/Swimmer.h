#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Swimmer {
private:
    string name;
    float speed;

public:
    void fillSwimmer();

    string getName() const;

    int timeSecond() const;

};
