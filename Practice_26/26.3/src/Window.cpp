#include "window.h"
#include <iostream>

using namespace std;

int Window::inputArgument(int bufRight, int bufLeft = 0){
    int argument;
    do {
        cin >> argument;
        if (argument > bufRight) cout << "too much" << endl;
        if (argument < bufLeft) cout << "too few" << endl;
    } while (argument < bufLeft || argument > bufRight);

    return argument;
}

void Window::clearScreen() {
    for (int i = 0; i < MAX_Y; i++)
        for (int j = 0; j < MAX_X; j++) {
            if (i == 0 || i == MAX_Y - 1 || j == 0 || j == MAX_X - 1) *(screen + (MAX_Y * j + i)) = true;
            else *(screen + (MAX_Y * j + i)) = false;
        }

}

void Window::screenFill(){

    for (int i = window.start.y; i <= window.end.y; i++)
        for (int j = window.start.x; j <= window.end.x; j++){
            if (i == window.start.y || i == window.end.y) *(screen + (MAX_Y * j + i)) = true;
            if (j == window.start.x || j == window.end.x) *(screen + (MAX_Y * j + i)) = true;
        }
}


void Window::resizeWindow(){
    cout << "Enter window width:";
    window.end.x = inputArgument(MAX_X - 1);
    cout << "Enter window length:";
    window.end.y = inputArgument(MAX_Y - 1);

}

void Window::moveWindow(){
    point shift;
    cout << "enter a shift in x: ";
    shift.x = inputArgument(MAX_X - 2 - window.end.x, 1 - window.start.x);
    cout << "enter a shift in y: ";
    shift.y = inputArgument(MAX_Y - 2 - window.end.y, 1 - window.start.y);

    window.start.x += shift.x;
    window.end.x += shift.x;
    window.start.y += shift.y;
    window.end.y += shift.y;

    cout << "window moved to (" << shift.x << "; " << shift.y << ")" << endl;
}

void Window::displayWindow() {
    clearScreen();
    screenFill();

    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++)
            cout << (*(screen + (MAX_Y * j + i)) ? "#" : " ");

        cout << endl;
    }
}

