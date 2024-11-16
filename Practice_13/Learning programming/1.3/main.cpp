#include <iostream>
#include <vector>

using namespace std;

int seekMax (int N,vector<int> vec, int max){
    for (int i = 0; i < N; i++){
        if (vec[i] > max)
            max = vec[i];
    }
    return max;
}

int main() {
    int N;
    cout << "Enter N:";
    cin >> N;

    vector<int> nums(N);
    cout << "Enter nums(" << N << ")\n";
    for (int i = 0; i < N; i++){
        cin >> nums[i];
    }

    int numMax = seekMax(N, nums, 0);

    for (int i = 0; i < N; i++){
        if (nums[i] == numMax)
            nums[i] = 0;
    }

    cout << "Second max number is " << seekMax(N, nums, 0);
    return 0;
}
