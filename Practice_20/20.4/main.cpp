#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int  countOfBill (int money) {
    int countMoney = 0;
    while (money >= 5000) {
        money -= 5000;
        countMoney++;
    }
    while (money >= 2000) {
        money -= 2000;
        countMoney++;
    }
    while (money >= 1000) {
        money -= 1000;
        countMoney++;
    }
    while (money >= 500) {
        money -= 500;
        countMoney++;
    }
    while (money >= 200) {
        money -= 200;
        countMoney++;
    }
    while (money >= 100) {
        money -= 100;
        countMoney++;
    }
    return countMoney;
}

int banknoteSelection(int& money){
    if (money >= 5000){
        money -= 5000;
        return 5000;
    } else if (money >= 2000){
        money -= 2000;
        return 2000;
    } else if (money >= 1000){
        money -= 1000;
        return 1000;
    } else if (money >= 500){
        money -= 500;
        return 500;
    } else if (money >= 200){
        money -= 200;
        return 200;
    } else if (money >= 100){
        money -= 100;
        return 100;
    } else return 0;
}

void fillingTheBank(int* bills, int& sum, ofstream& bankWrt){
    if (bankWrt.is_open()) {
        for (int i = 0; i < 1000; i++) {
            bankWrt << *(bills + i);
            if (i < 999) bankWrt << endl;
        }
    }
}

void fillingTheBankCondition(ofstream& bankConditionWrite, int& sum, int& count){
    if (bankConditionWrite.is_open()){
        bankConditionWrite << count << endl;
        bankConditionWrite << sum;
    }
}

int main() {
    cout << "\nTask  #4.\n  Implementation of the ATM simulation\n" << endl;

    srand(time(nullptr));
    int money[] = {100, 200, 500, 1000, 2000, 5000};
    int bank[1000];
    int sum = 0;
    int billCount = 1000;
    int clientMoney;
    for (int i = 0; i < 1000; i++) {
        bank[i] = money[rand() % 6];
        sum += bank[i];
    }


    // Global filling the bank
    ofstream bankWrite("bank.txt");
    fillingTheBank(bank, sum, bankWrite);
    bankWrite.close();

    // Global filling the bank condition
    ofstream bankConditionWrite("bank condition.txt");
    fillingTheBankCondition(bankConditionWrite, sum, billCount);
    bankConditionWrite.close();


    int command = 0;
    while (command != -1) {
        cout << "\nWho you are?"
                "\n\t\"1\" - client"
                "\n\t\"2\" - bank administrator"
                "\nTo exit the program enter \"-1\"" << endl;
        cin >> command;
        if (command != -1) {
            // Read the bank
            ifstream bankRead("bank.txt");
            if (bankRead.is_open()){
                for (int i = 0; i < 1000; i++)
                    bankRead >> bank[i];
                bankRead.close();
            }
            // Read the bank condition
            ifstream bankConditionRead("bank condition.txt");
            if (bankConditionRead.is_open()) {
                bankConditionRead >> billCount;
                bankConditionRead >> sum;
                bankConditionRead.close();
            }

            if (command == 2) {
                clientMoney = 0;

                if (billCount < 1000) {
                    cout << "enter \"1\" for complete filling:";
                    int com;
                    cin>> com;
                    if (com == 1){
                        for (int i = 0; i < 1000; i++)
                            if (bank[i] == 0) {
                                bank[i] = money[rand() % 6];
                                sum += bank[i];
                                billCount++;
                            }
                    }
                }

            } else if (command == 1) {
                int withdraw;
                do {
                    cout << "how mach money would you like?" << endl;
                    cin >> withdraw;
                    if (withdraw % 100 != 0) cout << "the smollest bill is 100\n\ttry again:" << endl;
                    if (withdraw < 0) withdraw = abs(withdraw);
                } while (withdraw % 100 != 0);
                clientMoney = withdraw;

                if (withdraw >= sum) {
                    clientMoney = sum;
                    sum = 0;
                    billCount = 0;
                    for (int i = 0; i < 1000; i++)
                        bank[i] = 0;

                } else {
                    int count = countOfBill(withdraw);
                    for (int i = 0; i < count; i++) {
                        int banknote = banknoteSelection(withdraw);
                        for (int j = 0; j < 1000; j++) {
                            if (bank[j] == banknote) {
                                billCount--;
                                sum -= bank[j];
                                bank[j] = 0;
                                break;
                            }
                        }
                    }
                }
            }
                cout << "\n------------------------------------------\n";
                if (command == 1) cout << "withdrawn money = " << clientMoney << endl;
                cout << "amount in the bank = " << sum << endl;
                cout << "number of banknotes in the bank = " << billCount << endl;
                cout << "------------------------------------------" << endl;


            // Local filling the bank
            bankWrite.open("bank.txt");
            fillingTheBank(bank, sum, bankWrite);
            bankWrite.close();

            // Local filling the bank condition
            bankConditionWrite.open("bank condition.txt");
            fillingTheBankCondition(bankConditionWrite, sum, billCount);
            bankConditionWrite.close();

        }

    }
    return 0;
}
