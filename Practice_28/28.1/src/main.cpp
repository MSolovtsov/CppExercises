#include <iostream>
#include <thread>
#include <mutex>
#include "Swimmer.h"

using namespace std;

int count = 0;
mutex mtx;

void result(Swimmer swimmer){
    this_thread::sleep_for(chrono::seconds(swimmer.timeSecond()));
    mtx.lock();
    count++;
    cout << count << ". \t"<< swimmer.getName() << "\t" << swimmer.timeSecond() << " sec"<< endl;
    mtx.unlock();
}

int main() {
    cout << "\nTask #1\n  Swimming 100 meters\n" << endl;

    Swimmer *swimmers = new Swimmer[6];

    for (int i = 0; i < 6; i++) {
        (swimmers + i)->fillSwimmer();
        cout << "-------------------------\n";
    }

    thread thrd_0(result, ref(*(swimmers)));
    thread thrd_1(result, ref(*(swimmers + 1)));
    thread thrd_2(result, ref(*(swimmers + 2)));
    thread thrd_3(result, ref(*(swimmers + 3)));
    thread thrd_4(result, ref(*(swimmers + 4)));
    thread thrd_5(result, ref(*(swimmers + 5)));

    thrd_0.join();
    thrd_1.join();
    thrd_2.join();
    thrd_3.join();
    thrd_4.join();
    thrd_5.join();



    delete[] swimmers;
    return 0;
}
