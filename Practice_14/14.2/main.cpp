#include <iostream>

using namespace std;

void print_game_field (int array[][3]){
    //system("cls");
    cout << "\n#2  Tic-tac-toe.\n" << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (array[i][j] == 1) cout << " X";
            else if (array[i][j] == -1) cout << " O";
            else cout << "  ";
            if (j < 2)
                cout << " |";
        }
        if (i < 2)
            cout << "\n---+---+---" << endl;
    }
    cout << endl << endl;
}

bool isHorizontVictory(int array[][3], int c){
    int coincidences = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (array[i][j] == c) coincidences++;
        }
        if (coincidences == 3) return true;
        coincidences = 0;
    }
    return false;
}

bool isVerticalVictory (int array[][3], int c){
    for (int j = 0; j < 3; j ++)
        if (array[0][j] == array[1][j] && array[1][j] == array[2][j] && array[2][j] == c)
            return true;
    return false;
}

bool isWin (int array[][3], int c){
    if (!isHorizontVictory(array, c)){
        if (!isVerticalVictory (array, c)){
            return ((array[0][0] == array[1][1] && array[1][1] == array[2][2] && array[2][2] == c) ||
                    (array[0][2] == array[1][1] && array[1][1] == array[2][0] && array[2][0] == c));
        } else return true;
    } else return true;
}

int main() {
    int gameField[3][3] = {{0,0,0},
                           {0,0,0},
                           {0,0,0}};

    int i, j;
    int count = 0;
    bool isFull = false;
    bool error = false;
    char mark = 'X';
    do {
        print_game_field(gameField);
        if (error){
            cout << "Error. Cell is not empty.\n" << endl;
            error = false;
        }
        cout << "Enter '"<< mark <<"' coordinates [1;3]\n"
             << count << " moves passed." << endl;
        cout << "\tvertical:";
        cin >> i;
        cout << "\thorizontal:";
        cin >> j;
        i--;
        j--;
        if (i < 0 || i > 2 || j < 0 || j > 2) error = true;
        else {
            if (count % 2 == 0 && gameField[i][j] == 0) {
                gameField[i][j] = 1;
                isFull = isWin(gameField, 1);
                mark = 'O';
            } else if (count % 2 != 0 && gameField[i][j] == 0) {
                gameField[i][j] = -1;
                isFull = isWin(gameField, -1);
                mark = 'X';
            } else {
                error = true;
                count--;
            }
            count++;
        }
    } while (count < 9 && !isFull);

    print_game_field(gameField);
    if (isFull) {
        mark = (count % 2 != 0) ? 'X' : 'O';
        cout << "WIN:  '" << mark << "' !!!" << endl;
    } else cout << "Nobody!" << endl;
    return 0;
}