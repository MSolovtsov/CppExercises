#include "Branch.h"

void Branch::setName(string inName) {
    this->name = inName;
    if (this->name != "None")
        this->thereIsElf = true;
}
