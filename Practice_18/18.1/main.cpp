#include <iostream>
#include <vector>

using namespace std;

void swapvec(vector<int>& vec, int* arr) {
    for (int i = 0; i < vec.size(); i++){
        int buf = *(arr + i);
        *(arr + i) = vec[i];
        vec[i] = buf;
    }
}

int main() {
    cout << "\nTask  #1\n" << endl;

    vector<int> a = {1,2,3,4};
    int b[] = {2,4,6,8};
    swapvec(a,b);

    for(int i = 0; i < 4; ++i)
        cout << a[i] << " ";
    cout << endl;

    for(int i = 0; i < 4; ++i)
        cout << b[i] << " ";
    return 0;
}
