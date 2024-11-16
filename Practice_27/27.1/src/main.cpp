#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tree.h"

using namespace std;

int main() {
    cout << "\nTask #1\n  Implementation of the village of elves\n" << endl;
    srand(time(nullptr));

    Tree* village = new Tree[5];

    for(int i = 0; i < 5; i++){
        cout << endl;
        cout << i + 1 << " Tree :" << endl;
        (village + i)->printNames();
        (village + i)->picture();
        for (int j = 0; j < (village + i)->getLargeSize(); j++) {
            cout << "__________";
        }
        cout << endl;
    }

    delete[] village;
    return 0;
}
