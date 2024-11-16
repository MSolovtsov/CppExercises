#include <iostream>

using namespace std;

int countJumping (int& num, int& lim) {
    if (num <= 0) return 0;
    int count = 0;

    for (int i = lim; i > 0; i --){
        if (num - i == 0) count++;
        else if (num - i > 0) {
            int newnum = num - i;
            count += countJumping(newnum, lim);
        }
    }

    return count;
}

int main() {
    cout << "\nTask  #3\n" << endl;

    int numStep;
    cout << "Enter number of step:";
    cin >> numStep;
    int limit;
    cout << "Enter step limit per jump:";
    cin >> limit;

    if (limit < 0 || numStep < 0) cout << "Silly.." << endl;
    else {
        if (limit > numStep) cout << "OK, I'll do it anyway, but I think you have a problem with logic.." << endl;
        cout << "Number of options = " << countJumping(numStep, limit) << endl;
    }
    return 0;
}