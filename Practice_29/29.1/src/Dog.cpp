#include "Dog.h"
#include <cmath>

bool bool_generator(){
    int value = rand() % 10;
    return (value % 2 != 0);
}

Dog::Dog(string _name) {
    this->name = _name;

    if (bool_generator()) {
        this->talents.push_back(new Swimming());
    }

    if (bool_generator()) {
        this->talents.push_back(new Dancing());
    }

    if (bool_generator()) {
        this->talents.push_back(new Counting());
    }
}

string Dog::getName(){
    return this->name;
}

void Dog::show_talents(){
    for (int i = 0; i < this->talents.size(); i++)
        this->talents[i]->talantOut();
}

Dog::~Dog(){
    this->talents.clear();
}