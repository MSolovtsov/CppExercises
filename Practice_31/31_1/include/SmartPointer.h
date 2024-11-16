#pragma once

#include <iostream>
#include <vector>

using namespace std;


class Toy {
private:
    string name;
    int count = 0;

protected:

public:
    Toy() : name("SomeName") {}

    Toy(string _name) : name(_name) {}

    string getName();

    void add();

    void remove();

    int getCount();
};

class SmartPointerToy : protected Toy{
private:
    Toy *ptr;

public:
    SmartPointerToy(Toy *_ptr);

    SmartPointerToy(const SmartPointerToy &oth);

    ~SmartPointerToy();

    SmartPointerToy &operator=(const SmartPointerToy &oth);

    Toy &operator*();

};
