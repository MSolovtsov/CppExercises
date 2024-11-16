//#include "../include/kbd.h"
#include "../include/ram.h"
#include <iostream>

void input(){
    /*for (int i = 0; i < 8; i++) {
        cout << "byte buffer " << i + 1 << ": ";
        cin >> byteBuffers[i];
    }*/

    for (int i = 0; i < 8; i++) {
        cout << "byte buffer " << i + 1 << ": ";
        int value;
        cin >> value;
        write(value, i);
    }
}
