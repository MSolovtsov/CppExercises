#include <iostream>

using namespace std;

void change (int* pa, int* pb){
    int buf = *pa;
    *pa = *pb;
    *pb = buf;
}

int main() {
    cout << "\nTask  #1\n" << endl;

    int a = 10;
    int b = 20;

    change(&a, &b);
    cout << a << " " << b;
    return 0;
}
