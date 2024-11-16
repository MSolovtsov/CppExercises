#include <iostream>
#include <mutex>
#include "Train.h"

using namespace std;

mutex mtx;

void railway_station(Train* train_type){
    if (train_type->isComing()){
        mtx.lock();
        cout << "Train " << train_type->getName() << " arrived at the station for " << train_type->getTime() << " sec." << endl;
        bool next = false;
        do {
            string command;
            cout << "Enter \"depart\" to let it go:";
            cin >> command;
            next = command == "depart";
            if (!next) cout << "I would advise you to let go.." << endl;
        } while(!next);
        cout << "--------------------\n";
        mtx.unlock();
    }
}


int main() {
    cout << "\nTask #2\n  Simulation of the station\n" << endl;

    srand(time(nullptr));

    Train* train_a = new Train('A');
    Train* train_b = new Train('B');
    Train* train_c = new Train('C');

    thread thrd_a(railway_station, train_a);
    thread thrd_b(railway_station, train_b);
    thread thrd_c(railway_station, train_c);

    thrd_a.join();
    thrd_b.join();
    thrd_c.join();

    delete train_a;
    delete train_b;
    delete train_c;
    return 0;
}
