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

int main() {
    vector<int> list = {};

    int sick;
    cout << "Enter age of sick person:";
    cin >> sick;
    int count = 0;
    while (sick != -1) {
        list = add(list, sick);
        count++;
        cout << "Enter age of sick person:";
        cin >> sick;
    }

    int average = 0;
    for (int i = 0; i < list.size(); i++)
        average += list[i];
    average /= count;

    cout << "Average age: " << average;
    return 0;
}
