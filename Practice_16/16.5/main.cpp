#include <iostream>

using namespace std;

enum switches
{
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};

void headProgramm(){
    //system("cls");
    cout << "\n#5  Smart House\n" << endl;
}

bool isRight(){
    string ans;
    do {
        cin >> ans;
        if (ans != "no" && ans != "yes")
            cout << "Impossible answer." << endl;
    } while (ans != "no" && ans != "yes");

    return ans == "yes";
}

void printHomeCondition (int waterPipeHeating, int lightsOutside, int heaters, int conditioner, int lightsInside, int colorTemperature){
    headProgramm();
    cout << "----------------------------\n";
    cout << "WATER PIPE HEATING:\t";
    if (waterPipeHeating & WATER_PIPE_HEATING) cout << "ON" << endl;
    else cout << "OFF" << endl;

    cout << "LIGHTS OUTSIDE:\t\t";
    if (lightsOutside & LIGHTS_OUTSIDE) cout << "ON" << endl;
    else cout << "OFF" << endl;

    cout << "HEATERS:\t\t";
    if (heaters & HEATERS) cout << "ON" << endl;
    else cout << "OFF" << endl;

    cout << "CONDITIONER:\t\t";
    if (conditioner & CONDITIONER) cout << "ON" << endl;
    else cout << "OFF" << endl;

    int temp = 0;
    cout << "LIGHTS INSIDE:\t\t";
    if (lightsInside & LIGHTS_INSIDE) {
        cout << "ON" << endl;
        temp = colorTemperature;
    } else cout << "OFF" << endl;
    cout << "color temperature:\t" << temp << " K" << endl;
    cout << "----------------------------\n";
    cout << "\n" << endl;
}

int main() {
    headProgramm();

    int time = 0;
    int colorTemperature = 5000;

    int lightsInside = LIGHTS_INSIDE;
    int lightsOutside = LIGHTS_OUTSIDE;
    int heaters = HEATERS;
    int waterPipeHeating = WATER_PIPE_HEATING;
    int conditioner = ~CONDITIONER;

    do {
        cout << "Time: " << time << ":00" << endl;

        cout << "Is the temperature outside below zero? (yes/no):";
        if (isRight()) waterPipeHeating |= WATER_PIPE_HEATING;
        else {
            cout << "The temperature outside is over five degrees? (yes/no):";
            if (isRight())
                waterPipeHeating &= ~WATER_PIPE_HEATING;
        }


        lightsOutside &= ~LIGHTS_OUTSIDE;
        if (time > 16 || time < 5) {
            cout << "It's already dark. Is there movement outside? (yes/no):";
            if (isRight())
                lightsOutside |= LIGHTS_OUTSIDE;
        }


        cout << "Is the temperature inside below 22 degrees? (yes/no):";
        if (isRight()) heaters |= HEATERS;
        else {
            cout << "Is the temperature inside above 25 degrees? (yes/no):";
            if (isRight()) {
                heaters &= ~HEATERS;
                cout << "Is the temperature inside above 30 degrees? (yes/no):";
                if (isRight()) conditioner |= CONDITIONER;
            } else {
                cout << "Temperature inside exactly 25 degrees? (yes/no):";
                if (isRight()) conditioner &= ~CONDITIONER;
            }
        }


        cout << "Is the light inside turned on? (yes/no):";
        if (isRight()) {
            lightsInside |= LIGHTS_INSIDE;
            if ((time > 16 && time < 20)) {
                colorTemperature -= 460;
            } else if (time == 0) colorTemperature = 5000;
        } else lightsInside &= ~LIGHTS_INSIDE;

        printHomeCondition (waterPipeHeating, lightsOutside, heaters, conditioner, lightsInside, colorTemperature);

        if (time == 23) time = 0;
        else time++;

    } while (time != 0);
    return 0;
}
