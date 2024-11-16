#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector<int> subtraction_from_the_list (vector<int> vec, int index){
    vector<int> list(vec.size());
    for (int i = 0; i < index; i++)
        list[i] = vec[i];
    for (int i = index + 1 ; i < vec.size(); i++)
        list[i-1] = vec[i];

    return list;
}

vector<int> enrollment_in_the_list (vector<int> vec, int count, int val){
    vec[vec.size() - count - 1] = val;
    return vec;
}

int enter_index (vector<int> vec, int i, int co){
    do {
        cout << "Enter index of robot [0; " << vec.size() -co << "]:";
        cin >> i;
    } while (i < 0 || i > vec.size() - 1);

    return i;
}

void print_list (vector<int> vec, int co){
    cout << "{ ";
    for (int i = 0; i < vec.size() - co; i++)
        cout << vec[i] << " ";
    cout << "}\n" << endl;
}

int main() {
    int n;
    cout << "Enter N:";
    cin >> n;

    vector<int> robotNums(n);
    for (int i = 0; i < robotNums.size(); i++) {
        cout << "\tenter number of robot:";
        cin >> robotNums[i];
    }
    int count = 0;
    print_list(robotNums, count);

    int value = 0;
    int request = 0;
    int index = 0;
    cout << "Enter a query like \n"
            "'1' - enrollment in the list\n"
            "'2' - subtraction from the list\n"
            "\tenter '-1', if you want to finish." << endl;
    while (robotNums[0] != 0 && request != -1) {
        cout << "\trequest:";
        cin >> request;
        assert(request == 1 || request == 2 || request == -1);

        if (request == 1) {
            if (robotNums.size() == robotNums.size() - count) {
                robotNums.resize(robotNums.size() + 10);
                count += 10;
            }
            count--;
            cout << "enter value:";
            cin >> value;
            robotNums = enrollment_in_the_list(robotNums, count, value);
            print_list(robotNums, count);

        } else if (request == 2) {
            count++;
            cout << "enter index:";
            index = enter_index(robotNums, index, count);
            cout << "Filling robot is { " << robotNums[index] << " }" << endl;
            robotNums = subtraction_from_the_list(robotNums, index);
            print_list(robotNums, count);

        } else
            print_list(robotNums, count);
    }
    return 0;
}

