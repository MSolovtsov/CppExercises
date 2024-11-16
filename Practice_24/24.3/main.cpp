#include <iostream>
#include <ctime>
#include <iomanip>

#include <unistd.h>

using namespace std;

int main() {
    cout << "\nTask #3\n  Implementation of the timer program\n" << endl;

    time_t t = time(nullptr);
    tm timer = *localtime(&t);
    cout << "Enter timer(mm/ss):" << endl;
    cin >> get_time(&timer, "%M/%S");

    while(!(timer.tm_sec == 0 && timer.tm_min == 0)) {
        system("cls");
        cout << put_time(&timer, "%M:%S");
        timer.tm_sec--;
        if (timer.tm_sec < 0 && timer.tm_min > 0){
            timer.tm_min--;
            timer.tm_sec += 60;
        }
        sleep(1);
    }

    cout << "\nDING! DING! DING!" << endl;
    return 0;
}
