#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>

using namespace std;

class Train {
private:
    char name;
    int sec;

public:
    Train(char name_char);

    char getName() const;

    int getTime() const;

    bool isComing();

};
