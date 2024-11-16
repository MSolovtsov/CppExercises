#include "ElvesNames.h"


string ElvesNames::strNames(int intElf) {
    Names elf = (Names)intElf;

    if (elf == Misha) return "Misha";
    else if (elf == Anton) return "Anton";
    else if (elf == Ilya) return "Ilya";
    else return "None";
}

void ElvesNames::countNames(int intElf) {
    this->counts[intElf]++;
}

int ElvesNames::getCountNames() const {
    return this->size;
}

int ElvesNames::get_arrayCount(int i) const {
    return this->counts[i];
}