#include <iostream>
#include <vector>

using namespace std;

vector<int> add_to_position(vector<int> vec, int val, int position){
    vector<int> newVec(vec.size() + 1);
    for (int i = 0; i < position; i ++)
        newVec[i] = vec[i];
    newVec[position] = val;
    for (int i = position + 1; i < vec.size() + 1; i++)
        newVec[i] = vec[i - 1];

    return newVec;
}

int enterNumber(int num){
    cout << "Enter number of robot:";
    cin >> num;

    return num;
}

int enterPosition (vector<int> vec, int num, int pos){
    do {
        if (num != -1) {
            cout << "\tenter its position [0; " << vec.size() - 1 << "]:";
            cin >> pos;
        }
    } while (pos < 0 || pos > vec.size() - 1);

    return pos;
}

void printVector (vector<int> vec){
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}

int main() {
    vector<int> list = {0, 1, 2, 3, 4, 5};

    int num = 0;
    int pos = 0;
    num = enterNumber(num);
    pos = enterPosition(list, num, pos);
    while (num != -1){
        list = add_to_position(list, num, pos);
        num = enterNumber(num);
        pos = enterPosition(list, num, pos);
    }

    printVector(list);
    return 0;
}
