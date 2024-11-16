#include "Dog.h"
#include "Nicknames.h"
#include <ctime>

int main() {
    cout << "\nTask #1\n  Superdog\n" << endl;
    srand(time(nullptr));

    Dog* dogs[8];
    Nicknames* nicks = new Nicknames();

    for (int i = 0; i < 8; i++){
        dogs[i] = new Dog(nicks->randNickname());
        cout << dogs[i]->getName() << endl;
        dogs[i]->show_talents();
    }

    delete nicks;
    for (int i = 0; i < 8; i++)
        delete dogs[i];
    return 0;
}
