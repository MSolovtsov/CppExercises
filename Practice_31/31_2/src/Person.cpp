#include "Person.h"

Person::Person(string _name){
    this->name = (_name != "") ? _name : "Person";
};

bool Person::isFriend(Person* person){
    for (int i = 0; i < this->social_circle.size(); i++){
        if (social_circle[i] == person) return true;
    }
    return false;
}

string Person::getName(){
    return this->name;
}

void Person::fillSocialCircle(Person* person) {
    if (this != person && !isFriend(person)){
        this->social_circle.push_back(person);
        person->fillSocialCircle(this);
    }
}

void Person::fillSocialCircle(int _size){
    int begin = this->social_circle.size();
    this->social_circle.resize(this->social_circle.size() + _size);
    for (int i = begin; i < this->social_circle.size(); i++){
        string _name;
        cout << i - begin + 1 << ". ";
        cin >> _name;
        social_circle[i] = new Person(_name);
        social_circle[i]->fillSocialCircle(this);
    }
}

Person* Person::getFriend(int i){
    if (i >= 0 && i < this->social_circle.size())
        return this->social_circle[i];
    else
        return nullptr;
}

int Person::getNumberOfFriends(){
    return this->social_circle.size();
}

void Person::ShowFriends(){
    for (int i = 0; i < this->social_circle.size(); i++){
        cout << this->social_circle[i]->getName() << endl;
    }
}