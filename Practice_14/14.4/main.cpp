#include <iostream>

using namespace std;

float inputMatrice (float matrice[][4]){
    for (int i  = 0; i < 4; i++)
        for (int j = 0; j < 4; j++){
            cout << "enter matrice[" << i << "][" << j << "]:";
            cin >> matrice[i][j];
        }
    cout << endl;
    return matrice[4][4];
}

int main() {
    cout << "\n#4  Multiplication of a matrix by a vector.\n" << endl;

    float matrix[4][4];
    matrix[4][4] = inputMatrice(matrix);
    float vector[4];
    for (int i = 0; i < 4; i++){
        cout << "enter vector[" << i << "]:";
        cin >> vector[i];
    }

    float multVector[4] = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            multVector[i] += matrix[i][j] * vector[j];

    cout << "\nResult:" << endl;
    for (int i = 0; i < 4; i++)
        cout << "| " << multVector[i] << " |" <<endl;

    return 0;
}
