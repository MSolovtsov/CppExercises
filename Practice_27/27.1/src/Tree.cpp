#include "Tree.h"

Tree::Tree(){
    this->largeSize = 3 + rand() % (5 - 3 + 1);
    largeBranch = new LargeBranch[largeSize];

    for(int i = 0; i < this->largeSize; i++) {
        for (int j = 0; j < getCountNames(); j++)
            this->counts[j] += (largeBranch + i)->get_arrayCount(j);
    }
}

void Tree::printNames(){
    for (int i = 0; i < getCountNames(); i++)
        cout << "\t" << strNames(i) << ": " << this->counts[i] << endl;
}

Tree::~Tree(){
    delete[] largeBranch;
}

int Tree::getLargeSize() const{
    return this->largeSize;
}

int Tree::branchPosition(int i) const{
    if (i == 0) return -1;
    else if (i == this->largeSize - 1) return 1;
    else return 0;
}

void shoulders_or_waist(int& weight, bool isShoulders = true){
    for (int i = 0; i < weight; i++){
        if (i < 4 || i > weight - 5) cout << " ";
        else if (i > 1 && i < 6) cout << ((isShoulders)? "\\" : "/");
        else if (i > weight - 7 && i < weight - 2) cout << ((isShoulders)? "/" : "\\");
        else cout << "|";
    }
    cout << endl;
}

void Tree::picture(){
    cout << endl;

    for (int i = 0; i < 7; i++){
        for (int j = 0; j < this->largeSize; j++){
            (largeBranch + j)->branchRoots(branchPosition(j));
            cout << (largeBranch + j)->getPictureBranch(i);
            cout << ((i < 6 || j == this->largeSize - 1) ? "   " : "___");

        }
        cout << endl;
    }

    int weight = 27 + (this->largeSize - 3) * 10;

    shoulders_or_waist(weight);
    for (int i = 0; i < 3; i++){
        for ( int j = 0; j < weight; j++){
            if (j < 5 || j > weight - 6) cout << " ";
            else cout << "|";
        }
        cout << endl;
    }

    shoulders_or_waist(weight, false);

    for ( int i = 0; i < weight; i++) {
        if (i < 3 || i > weight - 4 || i > 11 && i < weight - 12) cout << " ";
        else if ((i > 2 && i < 5) || (i > 9 && i < 12)) cout << "/";
        else if ( (i > weight - 13 && i < weight - 10) || (i > weight - 6 && i < weight - 3) )cout << "\\";
        else cout << "|";
    }
    cout << "\n" << endl;
}
