#include <iostream>

using namespace std;

int countFirst = 20;
int countSecond = 20;

void name_of_game(){
    //system("cls");
    cout << "\n#8  Sea battle!\n" << endl;
}

void print_with_parameter (char ch, int i, int j){
    if ( j == 0 && i == 0) cout << "   ";
    else if (j == 0) cout << i - 1 << " |";
    else if (i == 0) cout << " " << j - 1 ;
    else {
        cout << " " << ch << "";
        if (j == 10) cout << " |";
    }
}

void print_last_part (int i){
    cout << endl;
    if (i == 0 || i == 10){
        for (int j = 0; j < 11; j ++){
            if (j == 0) cout << "   -";
            else cout << "--";
        }
        cout << endl;
    }
}

void print_field (int arr[][10], bool isOpen){
    cout << endl;
    char ch = ' ';
    if (isOpen){
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                if (arr[i -1][j - 1] == 1) ch = '#';
                else if (arr[i -1][j - 1] == -1) ch = '!';
                else ch = ' ';
                print_with_parameter(ch, i, j);
            }
            print_last_part(i);

        }
    } else {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                if (arr[i -1][j - 1] == -1) ch = 'X';
                else if (arr[i -1][j - 1] == 2) ch = 'O';
                else ch = ' ';
                print_with_parameter(ch, i, j);
            }
            print_last_part(i);
        }
    }
}

bool range_check (int arr[][10], int l[2], int r[2], int cageNum){
    if (r[0] - l[0] + r[1] - l[1] != cageNum - 1) return false;
    else {
        for (int i = l[0]; i <= r[0]; i++)
            for (int j = l[1]; j <= r[1]; j++)
                if (arr[i][j] != 0)
                    return false;
    }

    return true;
}

int shot_cage (int arr[10][10], int inGameArr[10][10], bool isPlaying) {
    bool isCorrect = false;
    do {
        cout << "\nEnter cage (x, y):";
        int x, y;
        cin >> x >> y;

        if (x >= 0 && x < 10 &&
            y >= 0 && y < 10) {

            if (arr[x][y] == 1) {
                arr[x][y] = -1;
                cout << "You hit the target" << endl;

                name_of_game();
                if (isPlaying) {
                    print_field(inGameArr, isPlaying);
                    print_field(arr, !isPlaying);
                    countSecond --;
                } else {
                    print_field(arr, isPlaying);
                    print_field(inGameArr, !isPlaying);
                    countFirst --;
                }

                if (countFirst > 0 && countSecond > 0) arr[10][10] = shot_cage(arr, inGameArr, isPlaying);

            } else if (arr[x][y] != -1)
                arr[x][y] = 2;

            isCorrect = true;
        }

    } while (!isCorrect);

    return arr[10][10];
}

int input_one_cage_ship(int arr[][10]){
    bool isCorrect = false;
    do {
        cout << "\tinput (1 cage) ship (x, y):";
        int x, y;
        cin >> x >> y;
        if (x >= 0 && x < 10 &&
            y >= 0 && y < 10) {

            if (arr[x][y] == 0) {
                arr[x][y] = 1;
                isCorrect = true;
            } else cout << "Error. Cage is occupied" << endl;
        } else cout << "Error. Cage is occupied" << endl;

    } while (!isCorrect);

    return arr[10][10];
}

int input_some_cage_ship(int arr[][10], int cageNum){
    int left[2] = {0, 0};
    int right[2] = {0, 0};
    bool isCorrect = false;
    do {
        cout << "\tinput (" << cageNum << " cages) ship (x, y):\n";
        cout << "\tfirst cage:";
        cin >> left[0] >> left[1];
        cout << "\tlast cage:";
        cin >> right[0] >> right[1];
        if (left[0] >= 0 && left[0] < 10 &&
            left[1] >= 0 && left[1] < 10 &&
            right[0] >= 0 && right[0] < 10 &&
            right[1] >= 0 && right[1] < 10) {

            if (left[0] > right[0]) swap(left[0], right[0]);
            if (left[1] > right[1]) swap(left[1], right[1]);
            if ((left[0] == right[0] || left[1] == right[1])
                && range_check(arr, left, right, cageNum)){

                isCorrect = true;
                for (int i = left[0]; i <= right[0]; i++)
                    for (int j = left[1]; j <= right[1]; j++)
                        arr[i][j] = 1;

            } else cout << "Error. Wrong range.\n" << endl;
        } else cout << "Error. Wrong range.\n" << endl;
    } while (!isCorrect);
}

int put_ship (int arr[][10], int cageNum){

//    arr[10][10] = (cageNum == 1) ? input_one_cage_ship(arr) : input_some_cage_ship(arr, cageNum);

    if (cageNum == 1)
        arr[10][10] = input_one_cage_ship(arr);
    else
        arr [10][10] = input_some_cage_ship(arr, cageNum);

    return arr[10][10];
}

void print_text_head (int arr[][10], int num){
    name_of_game();
    string number;
    if (num == 1) number = "First";
    else number = "Second";

    cout << number << " player.\nFill in the field.";
    cout << "\nEnter 10 ships." << endl;
    print_field(arr, true);
}

int field_filling (int arr[][10], int num){


    for (int i = 0; i < 4; i++) {
        print_text_head(arr, num);
        arr[10][10] = put_ship(arr, 1);
    }
    cout << endl;

    for (int i = 0; i < 3; i++) {
        print_text_head(arr, num);
        arr[10][10] = put_ship(arr, 2);
    }
    cout << endl;

    for (int i = 0; i < 2; i++){
        print_text_head(arr, num);
        arr[10][10] = put_ship(arr, 3);
    }

    cout << endl;

    print_text_head(arr, num);
    arr[10][10] = put_ship(arr, 4);

    print_text_head(arr, num);
    cout << endl;

    return arr[10][10];

}

int main() {
    int field_1[10][10] = {{0, 0, 0, 0, 0, 0,0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0,0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0,0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0,0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0,0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0,0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0,0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0,0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0,0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0,0, 0, 0, 0}};

    int field_2[10][10] =  {{0, 0, 0, 0, 0, 0,0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0,0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0,0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0,0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0,0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0,0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0,0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0,0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0,0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0,0, 0, 0, 0}};


    field_1[10][10] = field_filling(field_1, 1);
    field_2[10][10] = field_filling(field_2, 2);

    bool isOpen = true;
    int count = 0;
    do {
        name_of_game();
        print_field(field_1, isOpen);
        print_field(field_2, !isOpen);
        if (count % 2 == 0) {

            field_2[10][10] = shot_cage(field_2, field_1, isOpen);
            isOpen = false;
        } else {

            field_1[10][10] = shot_cage(field_1, field_2, isOpen);
            isOpen = true;
        }
        count ++;
    } while (countFirst > 0 && countSecond > 0);

    name_of_game();
    print_field(field_1, true);
    print_field(field_2, true);

    cout << (countFirst > 0 ? "First Win!!" : "Second Win!!");

    return 0;
}
