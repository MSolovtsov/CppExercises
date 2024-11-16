#include "LargeBranch.h"

LargeBranch::~LargeBranch() {
    delete[] smallBranches;
    //delete[] pictureLargeBranch;
}

int LargeBranch::get_CountSmallBranch() const {
    return this->size;
}

LargeBranch::LargeBranch() {
    for (int i = 0; i < this->size; i++) {
        int num = rand() % (getCountNames() - 0 + 1) + 0;
        countNames(num);
        setName(strNames(num) + to_string(get_arrayCount(num)));
    }
}
