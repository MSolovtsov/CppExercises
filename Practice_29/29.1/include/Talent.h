#pragma once
#include <iostream>

using namespace std;

class Talent {
public:
    virtual void talantOut() = 0;
};

class Swimming : virtual public Talent {
public:
    virtual void talantOut();
};

class Dancing : virtual public Talent {
public:
    virtual void talantOut();
};

class Counting : virtual public Talent {
public:
    virtual void talantOut();
};
