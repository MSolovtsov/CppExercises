#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter namber of integers \n";
    cin >> n;

    vector<int> numbers(n);
    int average = 0;
    cout << "Enter " << n << " integers \n";
    for (int i = 0; i < n; i++){
        cin >> numbers[i];
        average += numbers[i];
    }
    average /= n;
    cout << "Average: " << average;

    return 0;
}
