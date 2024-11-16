#include "../include/cpu.h"
#include "../include/ram.h"
#include <iostream>

void compute(){
    int sum = 0;
    for(int i = 0; i < 8; i++) {
        int value;
        read(value, i);
        sum += value;
    }
    cout << "Sum = " << sum << endl;
}
