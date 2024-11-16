#include "SmartPointer.h"

string Toy::getName() {
    return this->name;
}

void Toy::add() {
    this->count++;
}

void Toy::remove() {
    this->count--;
}

int Toy::getCount() {
    return this->count;
}


SmartPointerToy::SmartPointerToy(Toy *_ptr) {
    if (_ptr != nullptr) {
        this->ptr = _ptr;
        this->ptr->add();
    }

}

SmartPointerToy::SmartPointerToy(const SmartPointerToy &oth) {
    this->ptr = oth.ptr;
}

SmartPointerToy::~SmartPointerToy() {
    this->ptr->remove();
    delete this->ptr;
}

SmartPointerToy &SmartPointerToy::operator=(const SmartPointerToy &oth) {
    if (this == &oth)
        return *this;
    if (this->ptr != nullptr) {
        delete this->ptr;
    }
    this->ptr = new Toy(*oth.ptr);
    return *this;
}

Toy &SmartPointerToy::operator*() {
    return *this->ptr;
}
