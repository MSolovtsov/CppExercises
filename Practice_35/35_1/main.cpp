#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Case {
private:
    vector<T> array;
public:
    Case(initializer_list<T> parts) {
        array = parts;
    }

    vector<T> getCase(){
        return this->array;
    };
};

int main() {
    cout << "\nTask  #1" << endl;

    auto list = new Case<int>({1, 2, 3, 4, 5});
    for (auto i : list->getCase()){
        cout << i << " ";
    }
    cout << endl;



    return 0;
}
