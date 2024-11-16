#include <iostream>
#include <cpr/cpr.h>

using namespace std;

void console(){
    cout << "Commands:\n"
            "\t1. get\n"
            "\t2. post\n"
            "\t3. put\n"
            "\t4. delete\n"
            "\t5. patch\n"
            "\t6. exit" << endl;
}

int main() {
    cout << "\nTask #1\n  User requests\n" << endl;

    string command;
    cpr::Response response;

    do {
        bool onServer = true;
        string path = "http://httpbin.org/";
        console();
        cout << "\nEnter command: ";
        cin >> command;
        path += command;


        if (command == "get") response = cpr::Get(cpr::Url(path));
        else if (command == "post") response = cpr::Post(cpr::Url(path));
        else if (command == "put") response = cpr::Put(cpr::Url(path));
        else if (command == "delete") response = cpr::Delete(cpr::Url(path));
        else if (command == "patch") response = cpr::Patch(cpr::Url(path));
        else if (command == "exit") {
            cout << "Bue-bue!" << endl;
            onServer = false;
        }
        else {
            cout << "\tincorrect!" << endl;
            onServer = false;
        }

        if (onServer) cout << response.text << endl;
        cout << "\n====================================================\n" << endl;
    } while (command != "exit");

    return 0;
}
