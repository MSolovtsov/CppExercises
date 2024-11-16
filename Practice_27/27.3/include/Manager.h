#pragma once
#include "Worker.h"

class Manager : public Worker{
private:
    int specialNum;
    string nameManager = "None";
    int numberOfWorkers;
    Worker* workers;

    enum Task{
        A,
        B,
        C
    };

    static char charTask(Task i);

    void task_assignment(int& i);

public:

    void callManager(int i);

    void fillWorkers(int& num, int& direction);

    void printTeam();

};
