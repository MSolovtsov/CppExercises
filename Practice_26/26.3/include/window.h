#pragma once

const int MAX_X = 82;
const int MAX_Y = 52;

class Window{
private:
    bool *screen = new bool[MAX_X * MAX_Y];

    struct point{
        int x = 1;
        int y = 1;
    };
    struct frame{
        point start;
        point end;
    };
    frame window;

    int inputArgument(int bufRight, int bufLeft);

    void clearScreen();

    void screenFill();

public:

    ~Window(){
        delete [] screen;
    }

    void resizeWindow();

    void moveWindow();

    void displayWindow();

};
