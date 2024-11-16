#include <iostream>

using namespace std;

int main() {
    cout << "\n#6  Snake passage\n" << endl;

    int array[5][5];
    int count = 0;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            array[i][j] = count;
            count++;
        }

    cout << "Standard passage" << endl;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++)
            cout << array[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    cout << "Snake passage" << endl;
    int start = 0;
    int end = 4;
    for (int i = 0; i < 5; i++){
        if (start < end)
            for (int j = start; j <= end; j++)
                cout << array[i][j] << " ";
        else
            for (int j = start; j >= end; j--)
                cout << array[i][j] << " ";
        swap(start, end);
        cout << endl;
    }

    return 0;
}
