#pragma once
#include "Manager.h"

class Head_of_the_company : public Manager{
private:
    int company_direction;
    int numberOfManagers;
    Manager *teams;

public:

    Head_of_the_company();

};
