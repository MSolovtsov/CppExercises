#include <iostream>
using namespace std;

bool isGame(string str){
    for (int i = 0; i < str.length(); i ++){
        if (str[i] != 'X' && str[i] != 'O' && str[i] != '.')
            return false;
    }
    return true;
}

int numChar(string str, char c){
    int check = 0;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == c) check++;
    }
    return check;
}

bool isRightGame (string str1, string str2, string str3){
    int numX = numChar(str1, 'X') + numChar(str2, 'X') + numChar(str3, 'X');
    int numO = numChar(str1, 'O') + numChar(str2, 'O') + numChar(str3, 'O');

    return (numX == numO) || (numX == numO + 1);
}

bool isHorizontVictory (string str, char c){
    int coincidences = 0;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == c) coincidences++;
    }
    return (coincidences == 3);
}

bool isVerticalVictory (string str1, string str2, string str3, char c){
    for (int i = 0; i < 3; i ++){
        if (str1[i] == str2[i] && str2[i] == str3[i] && str3[i] == c) return true;
    }
    return false;
}

bool isWin (string str1, string str2, string str3, char c){
    if (!isHorizontVictory(str1, c) &&
            !isHorizontVictory(str2, c) &&
            !isHorizontVictory(str3, c)){
        if (!isVerticalVictory (str1, str2, str3, c)){
            if ((str1[0] == str2[1] && str2[1] == str3[2] && str3[2] == c) ||
                    (str1[2] == str2[1] && str2[1] == str3[0] && str3[0] == c))
                return true;
            else return false;
        } else return true;
    } else if (isHorizontVictory(str1, c) ||
                    isHorizontVictory(str2, c) ||
                    isHorizontVictory(str3, c))
                return true;
    else return false;
}

int main() {
    cout << "\n#4  Evaluation of the results of the game of tic-tac-toe\n" << endl;

    cout << "Enter the playing field (X, O or .):\n";
    string firstStr;
    string secondStr;
    string thirdStr;
    cin >> firstStr;
    if (firstStr.length() != 3)
        cout << "You don't know how to play tic-tac-toe?" << endl;
    else {
        cin >> secondStr;
        if (secondStr.length() != 3)
            cout << "You already have wrong input." << endl;
        else {
            cin >> thirdStr;
            if (thirdStr.length() != 3)
                cout << "Well, everything was fine, what happened?" << endl;
            else {
                if (!isGame(firstStr) || !isGame(secondStr) || !isGame(thirdStr))
                    cout << "Are you playing a different game?" << endl;
                else {
                    if (!isRightGame(firstStr, secondStr, thirdStr))
                        cout << "Impossible game." << endl;
                    else {
                        if (!isWin(firstStr, secondStr, thirdStr, 'X') &&
                            !isWin(firstStr, secondStr, thirdStr, 'O'))
                            cout << "Standoff" << endl;
                        else {
                            int numX = numChar(firstStr, 'X') + numChar(secondStr, 'X') + numChar(thirdStr, 'X');
                            int numO = numChar(firstStr, 'O') + numChar(secondStr, 'O') + numChar(thirdStr, 'O');

                            if (isWin(firstStr, secondStr, thirdStr, 'X') &&
                                !isWin(firstStr, secondStr, thirdStr, 'O') &&
                                numX > numO)
                                cout << "Defeated X!" << endl;
                            else {
                                if (!isWin(firstStr, secondStr, thirdStr, 'X') &&
                                    isWin(firstStr, secondStr, thirdStr, 'O') &&
                                    numO == numX)
                                    cout << "Defeated O!" << endl;
                                else
                                    cout << "Impossible outcome." << endl;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
