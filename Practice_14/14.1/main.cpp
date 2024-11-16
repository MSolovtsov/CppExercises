#include <iostream>

using namespace std;

void print_edges(){

    for (int i = 0; i < 9; i++){
        if (i == 0) cout << "+";
        else if (i == 8) cout << "--+";
        else cout << "----";
    }
    cout << endl;
}

void print_table (int arr1[2][6], int arr2[2][6], bool isChange) {
    string person[2][6] {{"i", "i", "V", "V", "i", "i"},
                         {"i", "i", "i", "i", "i", "i"}};
    if (isChange) person[0][4] +="i";
    cout << " ";
    for (int j = 0; j < 6; j++)
        cout << "  "<< person[0][j] << "  ";
    cout << endl;
    print_edges();
    for (int i = 0; i < 2; i++) {
        cout << "|";
        for (int j = 0; j < 6; j++)
            cout << " " << arr1[i][j] << "," << arr2[i][j] << " ";
        cout << "|";
        cout << endl;
    }
    print_edges();
    cout << " ";
    for (int j = 0; j < 6; j++)
        cout << "  "<< person[1][j] << "  ";
    cout << endl;
}

int main() {
    cout << "\n#1  Banquet table.\n" << endl;

    int cutlery[2][6] = {{3, 3, 4, 4, 3,3},
                         {3, 3, 3, 3, 3,3}};

    int plates[2][6] = {{2, 2, 3, 3, 2, 2},
                        {2, 2, 2, 2, 2, 2}};

    bool isChange = false;
    print_table (plates, cutlery, isChange);

    cutlery[1][2] -= 1;
    cutlery[0][2] -= 1;
    plates[0][2] -= 1;
    isChange = true;

    cout << endl;
    cout << "There have been some changes:\n" << endl;
    print_table (plates, cutlery, isChange);

    return 0;
}
