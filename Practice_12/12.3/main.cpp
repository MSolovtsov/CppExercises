#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

float travelTime(float distance, float speed){
    assert(speed > 0);
    assert(distance != 0);
    return fabs(distance / speed);
}

int main() {
    cout << "\n#3  Using assert\n" << endl;

    cout << "Enter distance coordinate:";
    float distance;
    cin >> distance;
    cout << "Enter speed value:";
    float speed;
    cin >> speed;

    cout << "------------------\n" <<
            "Travel time will be " << travelTime(distance, speed) << " sec." << endl;
    return 0;
}
