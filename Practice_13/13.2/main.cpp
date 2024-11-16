#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void print_vector(vector<float> vec){
    cout << "List of prices: { ";
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "}" << endl;
}

int main() {
    cout << "\nTask  #2\n" << endl;

    vector<float> prices {2.5, 4.25, 3.0, 10.0};
    vector<int> items {1, 1, 0, 3};
    print_vector(prices);

    float sum = 0.f;
    for (int i = 0; i < items.size(); i++) {
        assert(items[i] >= 0 && items[i] < prices.size());
        sum += prices[items[i]];
    }

    cout << "Sum = " << sum << endl;
    return 0;
}
