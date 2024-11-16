#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector<int> input_vector(vector<int> vec){
    cout<< "Input numbers:" << endl;
    for (int i = 0; i < vec.size(); i++){
        cout << "\t" << i+1 << ":";
        cin >> vec[i];
    }
    return vec;
}

vector<int> leaving_at_the_end (vector<int> vec, int index){
    int pocket = vec[index];
    for (int i = index; i < vec.size() - 1; i++ )
        vec[i] = vec[i + 1];
    vec[vec.size() - 1] = pocket;

    return vec;
}

void print_vector(vector<int> vec){
    cout << "Result: { ";
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "}" << endl;
}

int main() {
    cout << "\nTask  #1\n" << endl;

    cout << "Input vector size: ";
    int size;
    cin >> size;
    assert(size >= 0);
    vector<int> list(size);

    if (size > 0) {
        list = input_vector(list);
        cout << "Input number to delete: ";
        int delNum;
        cin >> delNum;

        for (int i = 0; i < list.size(); i++) {
            if (delNum == list[i]) {
                list = leaving_at_the_end(list, i);
                list.pop_back();
                i--;
            }
        }
    }

    print_vector(list);
    return 0;
}
