#include <iostream>

enum room_type {
    bedroom = 1,
    kitchen = 2,
    bathroom = 3,
    nursery = 4,
    living = 5
};

int main() {

    room_type room;
    int num = 3;
    room = (room_type)num;
    std::cout << room << std::endl;
    return 0;
}
