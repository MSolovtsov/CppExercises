#include <iostream>
#include <fstream>

using namespace std;

bool isDigit (string& date, int startPos, int endPos){
    for (int i = startPos; i < endPos; i++)
        if (!isdigit(date[i])) {
            return false;
        }
    return true;
}

bool isThertyOneDays (int month){
    if (month == 1 ||
            month == 3 ||
            month == 5 ||
            month == 7 ||
            month == 8 ||
            month == 10 ||
            month == 12)
        return true;
    else return false;
}

bool isALeapYear (string& date){
    if (stoi(date.substr(6, 4)) % 4 == 0) {
        if (stoi(date.substr(6, 4)) % 100 == 0 &&
                stoi(date.substr(6, 4)) % 400 != 0)
            return false;
        return true;
    }
    else return false;
}

void writeDate(ofstream& file){
    string date;
    bool isCorrect = false;
    while (!isCorrect){
        cout << "Enter date (DD.MM.YYYY):";
        cin >> date;
        if (date[2] == '.' && date[5] == '.')

            if (isDigit(date, 0, 2) &&
                    isDigit(date, 3, 5) &&
                    isDigit(date, 6, 10))

                if (stoi(date.substr(3, 2)) > 0 && stoi(date.substr(3, 2)) < 13)

                    if (stoi(date.substr(0, 2)) > 0)

                        if (isThertyOneDays(stoi(date.substr(3, 2)))){

                            if (stoi(date.substr(0, 2)) < 32)
                                isCorrect = true;

                        } else {
                            if (isALeapYear(date)) {
                                if (stoi(date.substr(3, 2)) == 2 && stoi(date.substr(0, 2)) < 30)
                                    isCorrect = true;
                            } else {
                                if (stoi(date.substr(3, 2)) == 2 && stoi(date.substr(0, 2)) < 29)
                                    isCorrect = true;
                            }
                            if (stoi(date.substr(0, 2)) < 31)
                                isCorrect = true;
                        }
        if (!isCorrect) cout << "\tincorrect!" << endl;

    }
    file  << date << " ";
}

int main() {
    cout << "\nTask  #1\n  Implementation of an entry in the accounting sheet\n" << endl;

    string firstName;
    string secondName;
    int money;
    ofstream outFile("report.txt", ios::app);
    if (outFile.is_open()) {
        cout << "'0' - exit" << endl;
        do {
            cout << "Enter first name:";
            cin >> firstName;
            if (firstName != "0") {
                outFile << firstName << " ";
                cout << "Enter second name:";
                cin >> secondName;
                outFile << secondName << " ";
                writeDate(outFile);
                do {
                    cout << "How mach " << firstName << " " << secondName << " is cost?:";
                    cin >> money;
                    if (money < 0) cout << "incorrect money" << endl;
                } while (money < 0);
                outFile << money << endl;
                cout << endl;
            }
        } while (firstName != "0");
        outFile.close();
    } else cout << "Oops, file not open." << endl;

    return 0;
}
