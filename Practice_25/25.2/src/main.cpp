#include <iostream>
#include "../include/cpu.h"
#include "../include/disk.h"
#include "../include/gpu.h"
#include "../include/kbd.h"

using namespace std;

void head(){
    system("cls");
    cout << "\nTask #2\n  Computer simulator project\n" << endl;
}

void control(){
    cout << "You have commands:" << endl;
    cout << "\tsum\n\tsave\n\tload\n\tinput\n\tdisplay\n\tcontrol\n\texit" << endl;
}

int main() {
    string command = "control";

    do {
        head();

        if (command == "sum")
            compute();
        else if (command == "save")
            save();
        else if (command == "load")
            load();
        else if (command == "input")
            input();
        else if (command == "display")
            display();
        else if (command == "control")
            control();
        else
            cout << "incorrect command!" << endl;

        cout << "-----------------------\n" << endl;
        cout << "Enter command:";
        cin >> command;

    } while(command != "exit");

    return 0;
}
