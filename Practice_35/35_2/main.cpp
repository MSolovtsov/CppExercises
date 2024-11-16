#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>

using namespace std;

auto countOfValue = [](vector<int>& v){
    unordered_set<int> nameSat;
    for (int & it : v){
        nameSat.insert(it);
    }
    auto u_ptr = make_unique<vector<int>>();
    for(int it : nameSat){
        u_ptr->push_back(it);
    }
    return u_ptr;
};

int main() {
    cout << "\nTask  #2" << endl;

    vector<int> vec {1, 3, 4, 5, 3, 5, 1, 6};
    auto count = countOfValue(vec);

    for(int & i : *count){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
