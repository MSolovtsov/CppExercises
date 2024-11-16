#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    cout << "\nTask  #1\n  Development of a program for searching words in a file\n" << endl;

    ifstream words;
    words.open("C:\\Users\\mikha\\Desktop\\SkillBox\\Practice 19\\19.1\\words.txt");
    int count = 0;
    cout << "Enter the word: ";
    string inputStr;
    cin >> inputStr;

    while (!words.eof()) {
        string outputStr;
        words >> outputStr;
        bool isInFile = true;
        if (outputStr.size() != inputStr.size()) isInFile = false;
        else {
            for (int i = 0; i < inputStr.size(); ++i)
                if (inputStr[i] != outputStr[i]) {
                    isInFile = false;
                    break;
                }
        }
        if (isInFile) count++;
    }

    words.close();

    cout << "'" << inputStr << "' occurs " << count << " times in the file " << endl;

    return 0;
}
