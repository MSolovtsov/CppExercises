#include <iostream>

using namespace std;

int inputMatrice (int matrice[][4]){
    for (int i  = 0; i < 4; i++)
        for (int j = 0; j < 4; j++){
            cout << "enter matrice[" << i << "][" << j << "]:";
            cin >> matrice[i][j];
        }
    cout << endl;
    return matrice[4][4];
}

bool isSame (int matr1[][4], int matr2[][4]){
    int count = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (matr1[i][j] == matr2[i][j]) count++;
    return (count == 16);
}

int make_a_diagonal_matrix (int matr[][4]){
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (i != j) matr[i][j] = 0;

    return matr[4][4];
}

void printMstrice (int matr[][4]){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << matr[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cout << "\n#3  Matrices\n" << endl;

    int matriceOne[4][4];
    int matriceTwo[4][4];

    cout << "Enter first matrice:" << endl;
    matriceOne[4][4] = inputMatrice(matriceOne);
    cout << "Enter second matrice:" << endl;
    matriceTwo[4][4] = inputMatrice(matriceTwo);

    if (isSame(matriceOne, matriceTwo)){
        cout << "Matrices are the same." << endl;
        printMstrice(matriceOne);
        cout << "\nMake a diagonal matrix:" << endl;
        matriceOne[4][4] = make_a_diagonal_matrix(matriceOne);
        printMstrice(matriceOne);
    } else {
        cout << "Matrices are not the same." << endl;
        cout << "\tfirst:" << endl;
        printMstrice(matriceOne);
        cout << "\tsecond: " << endl;
        printMstrice(matriceTwo);
    }

    return 0;
}
