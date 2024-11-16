#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "\nTask  #4\n" << endl;

    vector<int> vec = {-100,-50, -5, 1, 10, 15};

    int count = 0;
    for (int i = 0; i < vec.size(); i ++) {
        if (vec[i] < 0) count++;
        else break;
    }

    for (; count >= 0; count--) {
        for (int j = count + 1; j < vec.size(); j++) {
            if (abs(vec[j]) < abs(vec[j - 1])) swap(vec[j], vec[j - 1]);
            else break;
        }
    }

//    for (int i = 0; i < vec.size(); i++)
//        for (int j = 1; j < vec.size() - i; j++){
//            if (abs(vec[j]) < abs(vec[j - 1])) swap(vec[j], vec[j - 1]);
//        }

    cout << "{ ";
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "}" << endl;

    return 0;
}
