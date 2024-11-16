//#include "../include/gpu.h"
#include "../include/ram.h"
#include <iostream>

void display(){
    for (int i = 0; i < 8; i++) {
        int value;
        read(value, i);
        cout << "byte buffer " << i + 1 << ": " << value << endl;
    }
}