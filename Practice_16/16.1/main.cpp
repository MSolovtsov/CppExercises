#include <iostream>

using namespace std;

bool compare (float value, double reference, double epsilon){
    return  (value >= reference - epsilon) && (value <= reference + epsilon);
}

int main() {
    cout << "\n#1  Speedometer" << endl;

    float speed_value = 0.f;
    float delta;
    do {
        cout << "\nEnter speed difference: ";
        do {
            cin >> delta;
            if (speed_value + delta < 0 || speed_value + delta > 150) cout << "Wrong difference. \nTry again: ";
        } while (speed_value + delta < 0 || speed_value + delta > 150);
        speed_value += delta;

        char speed_str[10];
        for (int i = 0; i < 10; i ++)
            speed_str[i] = ' ';

        sprintf(speed_str, "%.1f", speed_value);
        speed_str[9] = 'h';
        speed_str[8] = '/';
        speed_str[7] = 'm';
        speed_str[6] = 'k';
        for (int i = 0; i < 10; i++)
            cout << speed_str[i];
    } while (!compare(speed_value, 0., 0.01));

    cout << "\nYou got to the place ;-)" << endl;
    return 0;
}
