#include <iostream>

using namespace std;

void printShell (bool arr[12][12], int flag){
    //system("cls");
    cout << "\n#5  The Shell\n" << endl;
    if (flag == 0) cout << "Welcome to play The Shell.\n" << endl;
    else if (flag == 1) cout << "PUP!\n" << endl;
    else if (flag == 2) cout << "Error. Wrong range.\n" << endl;

    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            if (arr[i][j]) cout << "o ";
            else cout << "x ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isFoolShell (bool arr[12][12]){
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            if (arr[i][j]) return true;
    return false;
}

int main() {
    cout << "\n#5  The Shell\n" << endl;

    bool shell[12][12];
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            shell[i][j] = true;

    int flagForPrint = 0;
    printShell(shell, flagForPrint);

    while (isFoolShell(shell)){
        flagForPrint = 1;
        int regionStart[2] = {0, 0};
        int regionEnd[2] = {0, 0};
        cout << "Enter Start & End of region [0; 11].\n"
                "\tSrart(x, y):";
        cin >> regionStart[0] >> regionStart[1];
        cout << "\tEnd:(x, y)";
        cin >> regionEnd[0] >> regionEnd[1];

        if (regionStart[0] > 11 || regionStart[0] < 0 ||
                regionStart[1] > 11 || regionStart[1] < 0 ||
                regionEnd[0] > 11 || regionEnd[0] < 0 ||
                regionEnd[1] > 11 || regionEnd[1] < 0)
            flagForPrint = 2;
        else {
            if (regionStart[0] > regionEnd[0]) swap(regionStart[0], regionEnd[0]);
            if (regionStart[1] > regionEnd[1]) swap(regionStart[1], regionEnd[1]);

            for (int i = regionStart[0]; i <= regionEnd[0]; i++)
                for (int j = regionStart[1]; j <= regionEnd[1]; j++)
                    shell[i][j] = false;

            printShell(shell, flagForPrint);
        }
    }

    return 0;
}
