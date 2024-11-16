#include <iostream>
#include <vector>

using namespace std;

vector<int> add (vector<int> vec, int num){
    vector<int> newVec(vec.size() + 1);

    for (int i = 0; i < vec.size(); i++)
        newVec[i] = vec[i];
    newVec[vec.size()] = num;

    return newVec;
}

void printVector (vector<int> vec){
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}

int main() {
    vector<int> list = {1, 34, 2, 5, 6, 90};

    int num = 0;
    while (num != -1){
        cout << "Enter number of robot:";
        cin >> num;
        list = add(list, num);
    }

    printVector(list);
    return 0;
}
