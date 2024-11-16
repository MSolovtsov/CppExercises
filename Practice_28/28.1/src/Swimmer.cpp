#include "Swimmer.h"

void Swimmer::fillSwimmer(){
    cout << "Enter swimmer's name:";
    cin >> this->name;
    cout << "enter his/her speed (m/s):";
    cin >> this->speed;
    this->speed = fabs(this->speed);
}

string Swimmer::getName() const{
    return this->name;
}

int Swimmer::timeSecond() const{
    return round(100 / this->speed);
}
