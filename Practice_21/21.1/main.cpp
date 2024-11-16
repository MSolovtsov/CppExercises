#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct sheet{
    string firstName = "unknown";
    string secondName = "unknown";
    string date = "00.00.0000";
    int money = 0;
};

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

bool isCorrectDate(string& date){
    if (date[2] == '.' && date[5] == '.')

        if (isDigit(date, 0, 2) &&
                isDigit(date, 3, 5) &&
                isDigit(date, 6, 10))

            if (stoi(date.substr(3, 2)) > 0 &&
                    stoi(date.substr(3, 2)) < 13)

                if (stoi(date.substr(0, 2)) > 0)

                    if (isThertyOneDays(stoi(date.substr(3, 2)))){

                        if (stoi(date.substr(0, 2)) < 32)
                            return true;

                    } else {
                        if (isALeapYear(date)) {
                            if (stoi(date.substr(3, 2)) == 2 &&
                                    stoi(date.substr(0, 2)) < 30)
                                return true;
                        } else {
                            if (stoi(date.substr(3, 2)) == 2 &&
                                    stoi(date.substr(0, 2)) < 29)
                                return true;
                        }
                        if (stoi(date.substr(0, 2)) < 31)
                            return true;
                    }
    return false;
}

void fillTheSheet(sheet* person){
    cout << "name:";
    cin >> person -> firstName;
    cout << "second name:";
    cin >> person -> secondName;

    string dateConsole;
    do {
        cout << "date (DD.MM.YYYY):";
        cin >> dateConsole;
        if (!isCorrectDate(dateConsole)) cout << "\tincorrect!" << endl;
    } while (!isCorrectDate(dateConsole));
    person -> date = dateConsole;

    string salary;
    bool isCorrect = false;
    while (!isCorrect){
        bool isNumber = true;
        cout << "salary:";
        cin >> salary;
        for (int i = 0; i < salary.size(); i++)
            if (!isdigit(salary[i])) {
                isNumber = false;
                break;
            }
        isCorrect = isNumber;
    }
    person -> money = stoi(salary);
}

void fillTheAccounting(ofstream& file, sheet& person){
    int len = person.firstName.size();
    file.write((char*)&len, sizeof(len));
    file.write(person.firstName.c_str(), len);

    len = person.secondName.size();
    file.write((char*)&len, sizeof(len));
    file.write(person.secondName.c_str(), len);

    len = person.date.size();
    file.write((char*)&len, sizeof(len));
    file.write(person.date.c_str(), len);

    file.write((char*)&person.money, sizeof(person.money));
}

void readTheAccounting(ifstream& file, sheet& person){
    int len;
    file.read((char*)&len, sizeof(len));
    person.firstName.resize(len);
    file.read((char*)person.firstName.c_str(), len);

    file.read((char*)&len, sizeof(len));
    person.secondName.resize(len);
    file.read((char*)person.secondName.c_str(), len);

    file.read((char*)&len, sizeof(len));
    person.date.resize(len);
    file.read((char*)person.date.c_str(), len);

    file.read((char*)&person.money, sizeof(person.money));
}

int main() {
    cout << "\nTask  #1.\n  Implementation of the accounting sheet\n" << endl;

    vector<sheet> workers(10);
    int count = 0;
    int command = 0;

    while (command != -2) {
        cout <<"\"1\" - enter into accounting\n"
                "\"2\" - view all accounting" << endl;
        cout << "Command:";
        cin >> command;
        if (command == 1) {
            ofstream accounting("Accounting.bin", ios::app);
            do {
                if (accounting.is_open()) {
                    if (count == workers.size() - 1) workers.resize(workers.size() + 10);
                    fillTheSheet(&workers[count]);
                    fillTheAccounting(accounting, workers[count]);
                } else cout << "Error. File is not open." << endl;
                count++;

                cout << "Enter \"-1\" to finish and \"0\" to continue:";
                cin >> command;
            } while (command != -1);
            accounting.close();
            workers.clear();
            cout << "--------------------------\n" << endl;

        } else if (command == 2) {
            ifstream accountingRead("Accounting.bin");
            if (accountingRead.is_open()) {
                cout << "\nin file:" << endl;
                sheet person;
                accountingRead.seekg(0);
                while (!accountingRead.eof()) {
                    readTheAccounting(accountingRead, person);
                    cout << person.firstName << " " << person.secondName
                         << " " << person.date << " " << person.money
                         << " RUB" << endl;
                }
            }
            accountingRead.close();
            cout << "--------------------------\n" << endl;
        }
        cout << "\"-2\" - exit" << endl;
    }
    return 0;
}
