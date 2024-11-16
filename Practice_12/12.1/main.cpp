#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "\n#1  Apartment house\n" << endl;
    string tenants[] = { "SidorovA", "IvanovA", "PetrovA", "SidorovB", "IvanovB",
                         "PetrovB", "SidorovC", "IvanovC", "PetrovC", "SidorovD" };
    cout << "Enter the numbers of three tenants: " << endl;
    int number;
    for (int i = 0; i < 3; i++){
        cin >> number;
        if (number > 0 && number < 11)
            cout << "person number " << number << ":\t" << tenants[number - 1] << endl;
        else {
            --i;
            cout << "Amm.. The number is not included in the range of apartments.\n" <<
                     "Try again: " << endl;
        }
    }
    return 0;
}
