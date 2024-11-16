#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> vec){
    cout << "{ ";
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "}" << endl;
}

int main() {
    vector<int> robots;

    int mark = 0;
    while (mark != -1) {
        cout << "enter robot number: ";
        cin >> mark;
        robots.push_back(mark);
    }

    print_vector(robots);
    return 0;
}
