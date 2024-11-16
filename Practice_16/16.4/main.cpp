#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

enum note
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

vector<vector<int>> inputArr(vector<vector<int>> arr) {
    for (int i = 0; i < 12; i++) {
        cout << i + 1 << ". Enter "<< 12 - i <<" consecutive numbers consisting of digits [0; 6]: " << endl;
        string inputStr;
        cin >> inputStr;

        bool isCorrect = true;
        for (int j = 0; j < inputStr.size(); j++)
            if (!isdigit(inputStr[j]) || inputStr[j] > '6') {
                isCorrect = false;
                break;
            }

        if (isCorrect){
            if (inputStr.size() > arr[i].size())
                arr[i].resize(arr[i].size() + (inputStr.size() - 10));
            for (int j = 0; j < inputStr.size(); j++)
                arr[i][j] =pow(2, inputStr[j] - '0');

        } else {
            cout << "Wrong value." << endl;
            i--;
        }
    }

    return arr;
}

void printNote (int numNote){
    if (numNote & DO)
        cout << "DO ";
    if (numNote & RE)
        cout << "RE ";
    if (numNote & MI)
        cout << "MI ";
    if (numNote & FA)
        cout << "FA ";
    if (numNote & SOL)
        cout << "SOL ";
    if (numNote & LA)
        cout << "LA ";
    if (numNote & SI)
        cout << "SI ";
}

int main() {
    cout << "\n#4  Mechanical piano\n" << endl;

    vector< vector<int> > accords(12, vector<int>(10));
    accords = inputArr(accords);
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < accords[i].capacity(); j++){
            if (accords[i][j] != 0) printNote(accords[i][j]);
            else break;
        }
        cout << endl;
    }

    return 0;
}
