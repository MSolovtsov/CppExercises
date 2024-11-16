#include "LargeBranch.h"

LargeBranch::LargeBranch(){
    this->smallSize = 2 + rand() % (3 - 2 + 1);
    smallBranches = new Branch[smallSize];

    for(int i = 0; i < this->smallSize; i++){
        int num = rand() % getCountNames();
        countNames(num);
        (smallBranches + i)->setName(strNames(num)/* + to_string(get_arrayCount(num))*/);
    }

    pictureBranch();
}

LargeBranch::~LargeBranch(){
    delete[] smallBranches;
}

void LargeBranch::pictureBranch(){
    string left = "|";
    string right = "|";
    if (this->smallSize == 2){
        for (int i = 0; i < 3; i++){
            if (i == 0) {
                left = smallBranches->pictureHead();
                right = (smallBranches + this->smallSize - 1)->pictureHead();

            } else if (i == 1) {
                left = "|";
                right = "|";

            } else {
                left = "\\";
                right = "/";
            }

            pictureLargeBranch[i] = " " + left + "   " + right +  " ";
        }
        for (int i = 3; i < 5; i++){
            pictureLargeBranch[i] = "  |||  ";
        }
    } else if (this->smallSize == 3){
        for (int i = 0; i < 3; i++){
            string middle = "|";
            if (i == 0) {
                left = smallBranches->pictureHead();
                middle = (smallBranches + 1)->pictureHead();
                right = (smallBranches + this->smallSize - 1)->pictureHead();

            } else if (i == 1) {
                left = "|";
                right = "|";

            } else {
                left = "\\";
                right = "/";
            }

            pictureLargeBranch[i] = left + "  " + middle + "  " + right;
        }
        for (int i = 3; i < 5; i++){
            pictureLargeBranch[i] = " ||||| ";
        }
    }
}

void LargeBranch::branchRoots(int pos){
    switch (pos) {
        case -1:
            pictureLargeBranch[5] = "  \\\\\\\\ ";
            pictureLargeBranch[6] = "   \\\\\\\\";
            break;
        case 0:
            if (this->smallSize == 2) {
                pictureLargeBranch[5] = "  |||  ";
                pictureLargeBranch[6] = "_/|||\\_";

            } else if (this->smallSize == 3){
                pictureLargeBranch[5] = " ||||| ";
                pictureLargeBranch[6] = "//|||\\\\";
            }
            break;
        case 1:
            pictureLargeBranch[5] = " ////  ";
            pictureLargeBranch[6] = "////   ";
            break;
    }
}

string LargeBranch::getPictureBranch(int i){
    return this->pictureLargeBranch[i];
}
