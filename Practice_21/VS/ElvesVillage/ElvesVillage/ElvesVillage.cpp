#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tree.h"

using namespace std;

int main() {
    cout << "\nTask #1\n  Implementation of the village of elves\n" << endl;
    srand(time(nullptr));

    Tree* village = new Tree[1];

    for (int i = 0; i < 1; i++) {
        cout << i + 1 << " Tree :" << endl;
        (village + i)->printNames();
        cout << "----------------" << endl;
        (village + i)->picture();
    }

    //    string name;
    //    cout << "elve:";
    //    cin >> name;
    //

    delete[] village;
    return 0;
}