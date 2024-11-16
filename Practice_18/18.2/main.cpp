#include <iostream>

using namespace std;

int countJumping (int& num){
    if (num <= 0) return 0;
    int count = 0;

    if (num - 3 == 0) count ++;
    else if (num - 3 > 0){
        int newnum = num - 3;
        count += countJumping(newnum);
    }
    if (num - 2 == 0) count++;
    else if (num - 2 > 0){
        int newnum = num - 2;
        count += countJumping(newnum);
    }
    if (num - 1 == 0) count++;
    else if (num - 1 > 0){
        int newnum = num - 1;
        count += countJumping(newnum);
    }

    return count;
}

int main() {
    cout << "\nTask  #2\n" << endl;

    int numStep;
    cout << "Enter number of step:";
    cin >> numStep;
    if (numStep < 0) cout << "Silly.." << endl;
    else cout << "Number of options = " << countJumping(numStep) << endl;
    return 0;
}
