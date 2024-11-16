#pragma once

#include <vector>
#include <memory>

#include "Talent.h"

class Dog
{
private:
    std::string _name;
    std::vector<std::unique_ptr<Talent>> _talents;

public:
    Dog(const std::string &name);

    void addTalent(std::unique_ptr<Talent> talent);
    void showTalents() const;
};
