#pragma once
#include "Branch.h"
#include <iostream>

using namespace std;

class ElvesNames {
private:
    enum Names {
        Misha,
        Anton,
        Ilya,
        None
    };

    int size = (int)None + 1;
    int counts[4] = { 0, 0, 0, 0 };
public:
    static string strNames(int intElf);

    void countNames(int intElf);

    int getCountNames() const;

    int get_arrayCount(int i) const;

};

