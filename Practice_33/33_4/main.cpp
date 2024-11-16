#include <iostream>

using namespace std;

template<typename T>
T average(T* array){
    T sum = 0;
    for (int i =0; i < 8; i++)
        sum += *(array + i);

    return (sum / 8);
}

template<typename T>
void fill(T* array){
    T input;
    for (int i = 0; i < 8; i++){
        cout << i << "  :\t";
        cin >> input;
        *(array + i) = input;
    }
}

int main() {
    cout << "\nTask  #4\n\tArithmetic mean in an array\n" << endl;

    int arrayInt[8];
    double arrayDouble[8];
    float arrayFloat[8];

    cout << "For INT:" << endl;
    fill(arrayInt);
    cout << "................" << endl;
    cout << average(arrayInt) << endl;
    cout << endl;

    cout << "For DOUBLE:" << endl;
    fill(arrayDouble);
    cout << "................" << endl;
    cout << average(arrayDouble) << endl;
    cout << endl;

    cout << "For FLOAT:" << endl;
    fill(arrayFloat);
    cout << "................" << endl;
    cout << average(arrayFloat) << endl;
    cout << endl;

    return 0;
}
