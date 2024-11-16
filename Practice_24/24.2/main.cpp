#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

struct birthday{
    string name = "name";
    tm date{};
};

bool isLeapYear(int& year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

int whatMonth(int& month, int year){
    if (month == 1){
        if (isLeapYear(year)) return 29;
        else return 28;
    } else if (month == 0 || month == 2 ||month == 4 || month == 6 || month == 7 || month == 9 || month == 11)
        return 31;
    else
        return 30;
}

int count_of_day(int& month, int day){
    time_t t = time(nullptr);
    tm* local = localtime(&t);
    day -= whatMonth(month, local->tm_year + 1900);
    for (int i = 0; i < ((month > 5) ? 5 : month); i++){
        day += whatMonth(i, local->tm_year);
    }
    if (month > 6){
        for (int i = 6; i < ((month < 11) ? month : 11); i++){
            day += whatMonth(i, local->tm_year + 1900);
        }
    }
    return day;
}

int main() {
    cout << "\nTask #2\n  Implementation of the birthday reminder program\n" << endl;

    vector<birthday> birthday_list;
    string name;

    cout << "enter \"end\" to finish" << endl;
    do {
        cout << "---------------" << endl;
        cout << "enter friend's name:";
        cin >> name;
        if (name != "end"){
            birthday person;
            person.name = name;
            cout << "enter " << name << "\'s birthday (YYYY/mm/dd):";
            time_t t = time(nullptr);
            person.date = *localtime(&t);
            cin >> get_time(&person.date, "%Y/%m/%d");
            person.date.tm_yday = count_of_day(person.date.tm_mon, person.date.tm_mday);
            birthday_list.push_back(person);
        }
    } while (name != "end");

    cout << "---------------------------------" << endl;
    cout << endl;
    int min = 366;
    vector<int> indexes;
    time_t now = time(nullptr);
    tm local = *localtime(&now);

    for (int i = 0; i < birthday_list.size(); i++) {
        cout << put_time(&birthday_list[i].date, "%Y.%m.%d") << "  " << birthday_list[i].name << endl;
        int diff = (int)difftime(birthday_list[i].date.tm_yday, local.tm_yday);
        if (diff <= min && diff > 0){
            if (diff != min) {
                indexes.clear();
                min = diff;
            }
            indexes.push_back(i);
        }
    }

    cout << endl;
    for (int i = 0; i < indexes.size(); i++) {
        if (min == 0)
            cout << "Happy birthday, " << birthday_list[indexes[i]].name << "!" << endl;
        else
            cout << birthday_list[indexes[i]].name << " has a birthday soon" << endl;
    }

    return 0;
}
