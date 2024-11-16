#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Worker {
private:
    string nameWorker = "None";
    char task_type;

    enum Names{
        Mikhail,
        Anton,
        Ilya,
        Andrew,
        Ivan,
        Oleg,
        Mark,
        Petr,
        Daniil,
        Alexey,
        Sergei
    };

    string nameStr();

public:
    void setTask(char type);

    char getTask() const;

    string getName() const;

};

