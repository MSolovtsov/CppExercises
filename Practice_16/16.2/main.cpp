#include <iostream>

using namespace std;

int main() {
    cout << "\n#2  Fractional stitcher\n" << endl;

    int toDot;
    int afterDot;

    cout << "Enter an integer (to the dot):";
    cin >> toDot;
    cout << "Enter a fractional(after the dot):";
    cin >> afterDot;

    string number_str = to_string(toDot) + '.' + to_string(afterDot);
    cout << "As string: ";
    for (int i = 0; i < number_str.size(); i++)
        cout << number_str[i];
    cout << endl;

    double number_double;
    number_double = stod( number_str);
    cout << "As double: " << number_double << endl;
    return 0;
}
