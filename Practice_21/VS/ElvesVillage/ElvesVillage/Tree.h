#pragma once
#include "LargeBranch.h"
#include <iostream>
#include <cstdlib>

class Tree : public LargeBranch {
private:
    int size = 1;//rand() % (5 - 3 + 1) + 3;
    LargeBranch* largeBranch = new LargeBranch[size];

    int counts[4] = { 0, 0, 0, 0 };
public:

    Tree();

    void printNames();

    void picture() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < this->size; j++) {
                cout << (largeBranch + j)->getPictureBranch(i) << "   ";
            }
            cout << endl;
        }
    }

    ~Tree();

};
