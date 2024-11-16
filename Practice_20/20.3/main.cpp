#include <iostream>
#include <fstream>

using namespace std;

bool isCorrectFish(string& f){
    if (f == "sunfish" ||
            f == "shad" ||
            f == "carp" ||
            f == "bass" ||
            f == "bullhead" ||
            f == "walleye" ||
            f == "catfish")
        return true;
    else {
        cout << "there isn't that fish.\n Try again." << endl;
        return false;
    }

}

int main() {
    cout << "\nTask  #3.\n  Implementation of the simulation of the game \"Fishing\"\n" << endl;

    cout << "What fish would you like?" << endl;
    string fish;
    do {
        cin >> fish;
    } while (!isCorrectFish(fish));

    ifstream river("river.txt");
    if (river.is_open()){
        int count = 0;
        river.seekg(0);
        ofstream basket("basket.txt", ios::app);
        if (basket.is_open()){
            string inRiverNow;
            while (!river.eof()){
                river >> inRiverNow;
                if (inRiverNow == fish){
                    count++;
                    basket << inRiverNow << "\n";
                }
            }
            cout << "\t" << count << " of " << fish << " you picked up!" << endl;
        } else cout << "No basket." << endl;
        river.close();
    } else cout << "Open the file." << endl;

    return 0;
}
