#include <iostream>
#include <map>
#include <ctime>
#include <vector>

using namespace std;

class Phone{
private:
    string account;
    string my_number;

    map<string, string> contacts;
    pair<string, string> selected;

    void clearPair(pair<string, string>& pair){
        pair.first = "";
        pair.second = "";
    }

    static bool isNum(string& num){
        if (num.size() != 10) return false;
        for (int i = 0; i < 10; i++)
            if (!isdigit(num[i])) return false;

        return true;
    }

    bool seekContact(){
        string input;
        cout << "Enter contact number:";
        cin >> input;
        for(map<string, string>::iterator it = contacts.begin();
            it != contacts.end(); it++)
            if (it -> second == input) {
                selected = *it;
                return true;
            }

        return false;
    }

public:

    pair<string, string> sms;

    string getMyNumber(){
        return my_number;
    }

    string getName(){
        return account;
    }

    void addNumber(){
        if (my_number.empty()){
            my_number = "+7";
            cout << "enter 10 digits: +7";
            string num;
            bool isCorrect;
            do {
                cin >> num;
                isCorrect = isNum(num);
                if (!isCorrect) cout << "\tincorrect. Try again:\n+7";
            } while (!isCorrect);
            my_number += num;

            cout << "Your name is ";
            cin >> account;
        } else
            cout << "You can't change the user's number!" << endl;
    };

    void addContact(Phone& contact){
        bool forRecording = true;
        for(map<string, string>::iterator it = contacts.begin();
                it != contacts.end(); it++)
            if (it -> second == contact.getMyNumber()){
                forRecording = false;
                break;
            }

        if (forRecording && contact.getMyNumber() != getMyNumber()) {
            selected.first = contact.getName();
            selected.second = contact.getMyNumber();
            contacts.insert(selected);
            cout << selected.first << " successfully added!" << endl;
            clearPair(selected);

        } else if (contact.getMyNumber() == getMyNumber())
            cout << "Error. This is our phone number" << endl;
        else
            cout << "Already exists" << endl;
    }

    void deleteContact(){
        if (seekContact())
            contacts.erase(selected.first);
        else
            cout << "no such number!" << endl;
        clearPair(selected);
    }

    void seeContacts(){
        cout << "Contacts:" << endl;
        int count = 1;
        for(map<string, string>::iterator it = contacts.begin();
                it != contacts.end(); it++) {
            cout << "\t" << count << ". " << it->first << "  " << it->second << endl;
            count++;
        }
    }

    void callContact(){
        if (seekContact()){
            cout << "CALL " << selected.first << endl;
            time_t timer = time(nullptr);
            cout << "enter \"stop\" when finished:";
            string command;
            do {
                cin >> command;
                if (command != "stop") cout << "\tincorrect" << endl;
            } while (command != "stop");
            cout << "Call stopped. " << difftime(time(nullptr), timer) << " sec." << endl;
        } else
            cout << "no such number!" << endl;

        clearPair(selected);
    }

    string sendSms(){
        cout << "Who do you want to send a message to?" << endl;
        seeContacts();
        if (seekContact())
            return selected.second;
        else
            return "none";
    }

    void smsAlert(){
        if (!sms.second.empty()){
            cout << "\nYou have an unread message:\n" << endl;
            cout << sms.first << endl;
            cout << sms.second << endl;
            clearPair(sms);

        }
        clearPair(selected);
    }

};

void seeNetwork(vector<Phone>& network){
    cout << "\nNumber of accounts:" << endl;
    for (int i = 0; i < network.size(); i++)
        cout << i + 1 << ". " << network[i].getName() << "   " << network[i].getMyNumber() << endl;

    cout << "---------------------------------\n" << endl;
}

int choiceFromNetwork(vector<Phone>& network){
    cout << "Digit:";
    int num;
    do {
        cin >> num;
        if (num < 1 || num > network.size()) cout << "\tincorrect" << endl;
    } while (num < 1 || num > network.size());
    return num - 1;
}

void controller(){
    cout << "Commands:" << endl;
    cout << "\tchange\n\tadd\n\tcall\n\tsms\n\texit" << endl;
}

int main() {
    cout << "\nTask #2\n  Implementation of the mobile phone simulation program\n" << endl;

    vector<Phone> network;
    Phone basic;

    string command;
    do {
        cout << "Create a new account? (Yes/No)";
        do {
            cin >> command;
            if (command != "No" && command != "Yes") cout << "\tincorrect" << endl;

        } while (command != "No" && command != "Yes");

        if (command == "Yes") {
            network.resize(network.size() + 1);
            network[network.size() - 1].addNumber();
        }
        cout << "---------------------------------\n" << endl;
    } while (command != "No");

    if (!network.empty()){
        controller();
        command = "change";

        do {
            if (command == "add") {
                seeNetwork(network);
                cout << "Which account do you want to add?" << endl;
                basic.addContact(network[choiceFromNetwork(network)]);

            } else if (command == "change"){
                seeNetwork(network);
                cout << "What account will you use?" << endl;
                basic = network[choiceFromNetwork(network)];

            } else if (command == "call") {
                basic.seeContacts();
                basic.callContact();

            } else if (command == "sms"){
                string contactNumber;
                contactNumber = basic.sendSms();
                if (contactNumber != "none") {
                    int num = 0;
                    for (int i = 0; i < network.size(); i++)
                        if (network[i].getMyNumber() == contactNumber) {
                            num = i;
                            break;
                        }

                    network[num].sms.first = basic.getName();
                    cout << "Massage: " << endl;
                    string massage;
                    //getline(cin, massage);
                    cin >> massage;
                    network[num].sms.second = massage;

                } else
                    cout << "no such number!" << endl;

            } else if (command != "exit")
                cout << "\tincorrect command" << endl;

            cout << "\n---------------------------------" << endl;
            cout << "Active account: " << basic.getName() << endl;
            basic.smsAlert();
            cout << "\nEnter command:";
            cin >> command;

        } while (command != "exit");

    } else
        cout << "I'm sorry, no one uses your telephone network..." << endl;

    return 0;
}
