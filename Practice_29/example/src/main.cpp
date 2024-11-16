#include "Dog.h"

int main()
{
    Dog dog("Бобик");

    dog.addTalent(std::make_unique<Swimming>());
    dog.addTalent(std::make_unique<Counting>());

    // или так
    std::unique_ptr<Dancing> dancing = std::make_unique<Dancing>();
    dog.addTalent(std::move(dancing));

    dog.showTalents();

    return 0;
}
