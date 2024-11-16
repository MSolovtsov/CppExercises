#include <iostream>

using namespace std;

bool seekSubstring (char* global, char* substring, int num){

    bool isOk = true;
    for (int j = 0; j < 11 - num; j++) {
        for (int i = j; i < j + num; i++) {
            if (*(global + i) != *(substring + i - j)) {
                isOk = false;
                break;
            } else
                isOk = true;
        }
        if (isOk)
            break;
    }

    return isOk;
}

int main() {
    cout << "\nTask  #3\n" << endl;

    char a[] = "Hello world";
    char b[] = "wor";
    char c[] = "banana";

    cout << seekSubstring(a, b, 3) << " " << seekSubstring(a, c, 6);

    return 0;
}
