#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void enterValue(int& value){
    do {
        cin >> value;
        if (value <= 0) cout << "Range error. Try again:";
    } while (value <= 0);
}

void enterPictureFrames(int& h, int& w){
    cout << "Enter picture hight:";
    enterValue(h);
    cout << "Enter picture weight:";
    enterValue(w);
}

int main() {
    cout << "\nTask  #2.\n  Implementation of drawing random pictures\n" << endl;

    srand(time(nullptr));
    int hight, weight;
    enterPictureFrames(hight, weight);

    ofstream pictute("pic.txt");
    if (pictute.is_open()){
        for (int i = 0; i < hight; i++){
            for (int j = 0; j < weight; j++)
                pictute << rand() % 2;
            pictute << "\n";
        }

        pictute.close();
    }

    return 0;
}
