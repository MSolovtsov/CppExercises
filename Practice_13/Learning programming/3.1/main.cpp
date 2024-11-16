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

int enter_index (vector<int> vec, int i){
    do {
        cout << "Enter index of robot [0; " << vec.size() - 1 << "]:";
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

    int index = 0;
    int times;
    cout << "How many times to pick up? ";
    cin >> times;
    assert(times >= 0 || times <= n);
    for (int i = 0; i < times; i++) {
        count++;
        index = enter_index(robotNums, index);
        cout << "Filling robot is { " << robotNums[index] << " }" << endl;
        robotNums = subtraction_from_the_list(robotNums, index);
        print_list(robotNums, count);
    }
    return 0;
}
