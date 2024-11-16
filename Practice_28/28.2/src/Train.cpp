#include "Train.h"

Train::Train(char name_char){
    this->name = name_char;
    this->sec = 1 + rand() % 40;
}

char Train::getName() const{
    return this->name;
}

int Train::getTime() const{
    return this->sec;
}

bool Train::isComing(){
    this_thread::sleep_for(chrono::seconds(getTime()));
    return true;
}
