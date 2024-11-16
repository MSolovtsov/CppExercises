#include "medical-instruments.h"
#include <iostream>

using namespace std;

int main() {
    cout << "\nTask #1\n  Simulator of operations\n" << endl;

    cut wound;
    string command = "scalpel";

    scalpel(wound);
    do {
        cout << "\nEnter command:";
        cin >> command;

        if (command == "scalpel")
            cout << "The operation is already underway!" << endl;

        else if (command == "hemostat")
            hemostat(wound);

        else if (command == "tweezers")
            tweezers(wound);

        else if (command == "suture")
            suture(wound);

        else
            cout << "\tincorrect command!" << endl;

    } while (command != "suture");

    return 0;
}
