#include <iostream>
#include "window.h"

using namespace std;

void control(){
    cout << "Your commands:" << endl;
    cout << "\tmove\n\tresize\n\tdisplay\n\tclose\n" << endl;
}

int main() {
    cout << "\nTask #3\n  Implementing a desktop window manager\n" << endl;

    Window *window = new Window;

    string command = "display";
    do {
        if (command == "move") {
            window->moveWindow();
        } else if (command == "resize") {
            window->resizeWindow();
        } else if (command == "display"){
            window->displayWindow();
        } else if (command != "close")
            cout << "\tincorrect!" << endl;

        cout << "\n------------------------------" << endl;
        control();
        cout << "Enter command:";
        cin >> command;

    } while (command != "close");

    delete window;
    

    return 0;
}
