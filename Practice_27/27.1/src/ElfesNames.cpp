#include "ElfesNames.h"


string ElfesNames::strNames(int intElf){
    Names elf = (Names)intElf;

    if (elf == Misha) return "Misha";
    else if (elf == Anton) return "Anton";
    else if (elf == Ilya) return "Ilya";
    else return "None";
}

void ElfesNames::countNames(int intElf){
    this->counts[intElf]++;
}

int ElfesNames::getCountNames() const{
    return this->size;
}

int ElfesNames::get_arrayCount(int i) const{
    return this->counts[i];
}
