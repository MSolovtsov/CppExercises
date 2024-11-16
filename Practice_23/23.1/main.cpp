#include <iostream>

#define MONDAY  1
#define TUESDAY  2
#define WEDNESDAY  3
#define THURSDAY  4
#define FRIDAY  5
#define SATURDAY  6
#define SUNDAY  7

using namespace std;

int main() {
    cout << "\nTask  #1\n  Implementing advanced input and output of days of the week\n" << endl;

    cout << "enter number of week day:";
    int day;
    cin >> day;
    switch (day) {
        case MONDAY:
            cout << "monday" << endl;
            break;
        case TUESDAY:
            cout << "tuesday" << endl;
            break;
        case WEDNESDAY:
            cout << "wednesday" << endl;
            break;
        case THURSDAY:
            cout << "thursday" << endl;
            break;
        case FRIDAY:
            cout << "friday" << endl;
            break;
        case SATURDAY:
            cout << "saturday" << endl;
            break;
        case SUNDAY:
            cout << "sunday" << endl;
            break;
        default:
            cout << "there's no such thing" << endl;
            break;
    }
    return 0;
}
