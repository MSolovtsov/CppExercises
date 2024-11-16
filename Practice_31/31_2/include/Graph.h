#pragma once
#include <iostream>
#include <vector>
#include "Person.h"

using namespace std;

class Graph : public Person {
private:
    Person* base;
    vector<Person*> queue;
    vector<Person*> checked;

    //bool isChecked(Person* person);

    string check(string _name);

    //void find_connections();

    void reload();

public:

    Graph(string name, Person* person);

    void reGraph(Person* person);

    string seek(string _name);

    Person* getFront();

    Person* getBack();

    void showMatrix();

    void showAllConections();

};
