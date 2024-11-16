#include <iostream>

using namespace std;

string encrypt_caesar(string str, int position){
    for (int i = 0; i < str.length(); i++){
        str[i] = (char)((int)str[i] + position);
    }
    return str;
}

string decrypt_caesar(string str, int position){
    for (int i = 0; i < str.length(); i++){
        str[i] = (char)((int)str[i] - position);
    }
    return str;
}

int main() {
    cout << "\n#1  Caesar's cipher\n" << endl;

    cout << "Enter a word:";
    string word;
    getline(cin, word);

    int shift;
    cout << "Enter a number to shift:";
    cin >> shift;
    if (shift == 0) {
        cout << "There is no point in a cipher if there is no shift." << endl;
        return -1;
    }


    cout << "---------------\n";
    cout << "I present your coding: " << encrypt_caesar(word, shift) << endl;
    cout << "I remind you that your word was: " << decrypt_caesar(encrypt_caesar(word, shift), shift) << endl;

    return 0;
}
