#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

class Nicknames {
protected:

    enum Nicks {
        Archie = 0,
        Baron = 1,
        Bolt = 2,
        Gorik = 3,
        Shatik = 4,
        Sherkhan = 5,
        Spike = 6,
        Tyson = 7
    };

public:

    string randNickname();


};
