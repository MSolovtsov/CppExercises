#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    cout << "\nTask #2\n  Registry\n" << endl;

    map<string, int> turn;

    cout << "enter the last name or string Next" << endl;

    string command;
    int count = 0;
    int index = 0;
    do {
        cin >> command;
        if (command == "Next") cout << "so far no one" << endl;
    } while (command == "Next" || command == "next");
    pair<string, int> surname;
    surname.first = command;
    surname.second = index;
    count++;
    turn.insert(surname);

    map<string, int>::iterator it;
    do {
        it = turn.begin();
        cin >> command;
        if (command == "Next") {
            cout << "Next is " << it->first<< "(" << it->second << ")" << endl;
            turn.erase(it);
            count--;
        } else {
            index++;
            surname.first = command;
            surname.second = index;
            turn.insert(surname);
            count++;
        }
    } while (count != 0);

    return 0;
}
