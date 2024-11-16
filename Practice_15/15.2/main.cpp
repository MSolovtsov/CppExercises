#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "\nTask  #2\n" << endl;

    vector<int> vec = {2, 7, 11, 15};
    int result = 9;
    int num1, num2;

    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] + vec[i - 1] == result) {
            num1 = vec[i];
            num2 = vec[i - 1];
            break;
        }
    }

    cout << "Numbers:  " << num2 << " + " << num1 << " = " << result << endl;
    return 0;
}
