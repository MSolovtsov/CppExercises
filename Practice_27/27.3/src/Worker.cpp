#include "Worker.h"

string Worker::nameStr(){
    int name = rand() % ((int)Sergei);
    switch ((Names)name) {
        case Mikhail: return "Mikhail";
        case Anton: return "Anton";
        case Ilya: return "Ilya";
        case Andrew: return "Andrew";
        case Ivan: return "Mikhail";
        case Oleg: return "Oleg";
        case Mark: return "Mark";
        case Petr: return "Petr";
        case Daniil: return "Daniil";
        case Alexey: return "Alexey";
        case Sergei: return "Sergei";
    }
}

void Worker::setTask(char type){
    this->task_type = type;
    this->nameWorker = nameStr();
}

char Worker::getTask() const {
    return this->task_type;
}

string Worker::getName() const{
    return this->nameWorker;
}