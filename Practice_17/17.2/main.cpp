#include <iostream>

using namespace std;

void changeArr (int* change){
    for (int i = 0; i < 5; i++)
        swap(*(change + i), *(change + (9 - i)));

}

int main() {
    cout << "\nTask  #2\n" << endl;

    int num [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    changeArr(num);

    for (int i = 0; i < 10; i++)
        cout << num[i] << " ";
    return 0;
}
