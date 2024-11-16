#include "Branch.h"

void Branch::setName(string inName){
    this->elfName = inName;

}

string Branch::pictureHead(){
    string head;
    if (this->elfName.substr(0,4) != "None") {
        head/*[0]*/ = this->elfName[0];
        //head[1] = this->elfName[elfName.length() - 1];
    }
    else
        head = " ";

    return head;
}
