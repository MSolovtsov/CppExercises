#pragma once
#include "Branch.h"
#include "ElvesNames.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class LargeBranch : public Branch, public ElvesNames {
private:
    int size = rand() % (3 - 2 + 1) + 2;
    Branch* smallBranches = new Branch[size];

    string pictureLargeBranch[5]; //= new char[7 * 5];

public:

    LargeBranch();

    int get_CountSmallBranch() const;

    void pictureBranch() {
        string left = "|";
        string right = "|";
        if (this->size == 2) {
            for (int i = 0; i < 3; i++) {
                if (i == 0) {
                    left = smallBranches->pictureHead();
                    right = (smallBranches + this->size - 1)->pictureHead();

                }
                else if (i == 1) {
                    left = "|";
                    right = "|";

                }
                else {
                    left = "\\";
                    right = "/";
                }

                pictureLargeBranch[i] = " " + left + "   " + right + " ";
            }
            for (int i = 3; i < 5; i++) {
                pictureLargeBranch[i] = "  |||  ";
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                string middle = "|";
                if (i == 0) {
                    left = smallBranches->pictureHead();
                    middle = (smallBranches + 1)->pictureHead();
                    right = (smallBranches + this->size - 1)->pictureHead();

                }
                else if (i == 1) {
                    left = "|";
                    right = "|";

                }
                else {
                    left = "\\";
                    right = "/";
                }

                pictureLargeBranch[i] = left + "  " + middle + "  " + right;
            }
            for (int i = 3; i < 5; i++) {
                pictureLargeBranch[i] = " ||||| ";
            }
        }
    }

    string getPictureBranch(int i) {
        return this->pictureLargeBranch[i];
    }

    ~LargeBranch();

};



