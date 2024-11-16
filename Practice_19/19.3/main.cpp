#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    cout << "\nTask  #3\n  Implementation of the bill reader\n" << endl;

    int totalMoney = 0;
    int maxMoney = 0;
    string theMostGreedy;

    ifstream state;
    state.open(R"(C:\Users\mikha\Desktop\SkillBox\Practice 19\19.3\statements.txt)");
    string firstName;
    string secondName;
    int money;
    string data;
    while (!state.eof()) {
        state >> firstName >> secondName >> money >> data;
        totalMoney += money;
        if (money > maxMoney) {
            maxMoney = money;
            theMostGreedy = firstName + " " + secondName;
        }
    }
    state.close();

    cout << "Total amount of money = " << totalMoney << "$" << endl;
    cout << "The most greedy is " << theMostGreedy << " with maximum earnings = " << maxMoney << "$" <<endl;
    return 0;
}
