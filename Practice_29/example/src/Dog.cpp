#include "Dog.h"

Dog::Dog(const std::string &name) : _name(name)
{

}

void Dog::addTalent(std::unique_ptr<Talent> talent)
{
    _talents.push_back(std::move(talent));
}

void Dog::showTalents() const
{
    for (const auto &talent : _talents)
        talent->showTalent();
}
