#include "Manager.h"

char Manager::charTask(Task i){
    switch (i) {
        case A: return 'A';
        case B: return 'B';
        case C: return 'C';
    }
}

void Manager::task_assignment(int& i){
    (this->workers + i)->setTask(charTask(((Task) (rand() % 3))));
}

void Manager::callManager(int i){
    cout << i + 1 << ". Enter name of  manager:";
    cin >> this->nameManager;
}

void Manager::fillWorkers(int& num, int& direction){
    this->specialNum = num + direction;
    srand(this->specialNum);
    cout << "Enter number of workers in this team:";
    cin >> this->numberOfWorkers;
    this->workers = new Worker[this->numberOfWorkers];
    for (int i = 0; i < this->numberOfWorkers; i++)
        task_assignment(i);
}

void Manager::printTeam(){
    cout << this->nameManager << endl;
    for (int i = 0 ; i < this->numberOfWorkers; i++)
        cout << "\t" << i + 1 << ". " << (this->workers + i)->getName() << " : " << (this->workers + i)->getTask() << endl;
    cout << "---------------------------------" << endl;
}


