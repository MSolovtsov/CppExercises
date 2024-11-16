#pragma once
#include "Talent.h"
#include <vector>
#include <cstdlib>

class Dog {
private:
    string name;
    vector<Talent*> talents;

public:
    Dog(string _name);

    string getName();

    void show_talents();

    ~Dog();

};
