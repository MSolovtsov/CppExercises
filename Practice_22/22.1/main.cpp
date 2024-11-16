#include <iostream>
#include <map>
#include <string>

using namespace std;

bool isNum (string substr){
    for (int i = 0; i < substr.size(); i++)
        if (!isdigit(substr[i])) return false;
    return true;
}

bool isPhoneNumber(string& number){
    if (number.size() != 8)
        return false;
    else if (number[2] != '-' || number[5] != '-')
        return false;
    else if (!(isNum(number.substr(0, 2)) &&
                    isNum(number.substr(3, 2)) &&
                    isNum(number.substr(6, 2))))
        return false;
    else
        return true;
}

void enter_phoneNumber(string& number){
    cout << "enter phone number:";
    bool isCorrectNum = false;
    do {
        cin >> number;
        isCorrectNum = isPhoneNumber(number);
        if (!isCorrectNum) cout << "\tincorrect\n";
    } while (!isCorrectNum);
}

int main() {
    cout << "\nTask  #1\n  Phonebook\n" << endl;

    map<string, string> phonebook;
    phonebook.insert(make_pair<string, string>("69-90-87", "Denezhko"));
    phonebook.insert(make_pair<string, string>("63-60-90", "Solovtsov"));
    phonebook.insert(make_pair<string, string>("39-54-12", "Chebotareva"));
    phonebook.insert(make_pair<string, string>("84-21-92", "Ilukhina"));
    phonebook.insert(make_pair<string, string>("69-73-15", "Denezhko"));

    string command;
    do {
        cout << "\"0\" - enter phone number & last name" << endl;
        cout << "\"1\" - find last name by phone number" << endl;
        cout << "\"2\" - find phone number by last name" << endl;
        cout << "enter:";
        do {
            cin >> command;
            if (command != "1" && command != "2" && command != "0" && command != "-1") cout << "\tincorrect!\n";
        } while (command != "1" && command != "2" && command != "0" && command != "-1");

        string number;
        if (command == "1") {
            enter_phoneNumber(number);
            cout << phonebook[number] << endl;

        } else if (command == "2") {
            cout << "enter last name:";
            cin >> number;
            for (map<string, string>::iterator it = phonebook.begin();
                 it != phonebook.end(); it++)
                if (it->second == number)
                    cout << it->first << "  ";
            cout << endl;
        } else if (command == "0"){
            pair<string, string> subscriber;
            enter_phoneNumber(subscriber.first);
            cout << "enter last name:";
            cin >> subscriber.second;
            phonebook.insert((subscriber));
        }
        cout << endl;
        cout << "\"-1\" - exit" << endl;
    } while (command != "-1");

    return 0;
}
