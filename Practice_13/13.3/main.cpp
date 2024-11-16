#include <iostream>
#include <vector>

using namespace std;

void print_vector (vector<int> vec, int co){
    if (co > vec.size()) co = vec.size();
    else co -= 1;
    int length = vec.size() - (vec.size() - co);
    cout << "Result { ";
    for (int i = 0; i < length; i++)
        cout << vec[i] << " ";
    cout << "}" << endl;
    cout << "\tsize: " << length << endl;
}

int main() {
    cout << "\nTask  #3\n" << endl;

    vector<int> db(20);
    cout << "Enter integer numbers,\n"
            "\tbut you have to know that 20 is max size of a list: " << endl;
    int count = 0;
    int num = 0;
    do {
        cout << count + 1 << ": ";
        cin >> num;
        if (count < db.size() && num != -1)
            db[db.size() - (db.size() - count)] = num;
        else {
            if (num != -1) {
                for (int i = 0; i < db.size(); i++) {
                    db[i] = db[i + 1];
                }
                db.back() = num;
            }
        }
        count ++;
    } while (num != -1);

    print_vector(db, count);
    return 0;
}
