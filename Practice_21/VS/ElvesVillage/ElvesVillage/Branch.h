#pragma once
#include <iostream>

using namespace std;

class Branch {
private:
    bool thereIsElf = false;
    string name;
public:

    void setName(string inName);

    string pictureHead() {
        string head;
        if (this->thereIsElf) {
            head/*[0]*/ = name[0];
            //head[1] = name[name.length() - 1];
        }
        else
            head = " ";

        return head;
    }



};
