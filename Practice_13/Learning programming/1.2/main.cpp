#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cout << "Enter N:";
    cin >> N;

    vector<float> nums(N);
    cout << "Enter nums(" << N <<") \n";

    for (int i = 0; i < N; i++){
        cin >> nums[i];
    }

    for (int i = N - 1; i >= 0; i--){
        cout << nums[i] << " ";
    }

    return 0;
}
