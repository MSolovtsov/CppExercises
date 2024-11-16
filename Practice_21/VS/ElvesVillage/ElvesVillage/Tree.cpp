#include "Tree.h"

Tree::Tree() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < getCountNames(); j++)
            this->counts[j] += (largeBranch + i)->get_arrayCount(j);
    }
}

void Tree::printNames() {
    for (int i = 0; i < getCountNames(); i++)
        cout << "\t" << strNames(i) << ": " << this->counts[i] << endl;
}

Tree::~Tree() {
    delete[] largeBranch;
}
