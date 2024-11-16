#pragma once
#include <iostream>
#include <vector>


using namespace std;

class Person {
private:
    string name;
    vector<Person*> social_circle;

    bool isFriend(Person* person);

public:
    Person(string _name);

    string getName();

    void fillSocialCircle(Person* person);

    void fillSocialCircle(int _size);

    Person* getFriend(int i);

    int getNumberOfFriends();

    void ShowFriends();

};