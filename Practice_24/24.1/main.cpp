#include <iostream>
#include <ctime>
#include <map>

using namespace std;

void guide(){
    cout << "\"begin\" - to start a new project" << endl;
    cout << "\"end\" - complete the project" << endl;
    cout << "\"status\" - view the time of all projects" << endl;
    cout << "\"guide\" - if you forgot the commands" << endl;
    cout << "\"exit\" - exit the program" << endl;
}

void project_closure(map<float, string>& document, string& name, time_t& start, time_t& end, bool& isOpen){
    end = time(nullptr);
    pair<float, string> finalProfect;
    finalProfect.first = difftime(end, start);
    finalProfect.second = name;
    document.insert(finalProfect);
    isOpen = false;
}

int main() {
    cout << "\nTask  #1\n  Implementation of the time tracking program\n" << endl;

    map<float, string> projects;
    string command = "guide";
    string projectName;
    time_t timeStart;
    time_t timeEnd;
    bool isOpened = false;

    do {
        if (command == "begin"){
            if (isOpened)
                project_closure(projects,projectName,timeStart,timeEnd,isOpened);

            cout << "Enter the name of the project:" << endl;
            cin >> projectName;
            timeStart = time(nullptr);
            isOpened = true;


        } else if (command == "end"){
            if (isOpened)
                project_closure(projects,projectName,timeStart,timeEnd,isOpened);
            else
                cout << "\tNew project has not started yet!" << endl;

        } else if (command == "status"){
            for (map<float, string>::iterator it = projects.begin();
                    it != projects.end(); it++){
                cout << "\"" << it -> second << "\": " << it -> first << " sec" << endl;
            }
        } else if (command == "guide")
            guide();

        else
            cout << "\tincorrect command!" << endl;

        cout << "-----------------------------" << endl;
         cout << "\nEnter the command:";
         cin >> command;


    } while (command != "exit");
    return 0;
}
