#include "../include/ram.h"

void write(int& buf, int i){
    *(byteBuffers + i) = buf;
}

void read(int& buf, int i){
    buf = *(byteBuffers + i);
}
