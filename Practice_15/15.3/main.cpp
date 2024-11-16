#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "\nTask  #3\n" << endl;

    vector<int> vec;

    int n = 0;
    int value = 0;

    cout << "Input value \n"
            "\t'-1' - print fifth largest element\n"
            "\t'-2' - finish programm\n" << endl;

    while (value != -2){
        cin >> value;
        if (value != -1 && value != -2){
            if (n % 10 == 0) vec.resize(vec.size() + 10);
            vec[n] = value;
            n++;
        } else if (value == -1){
            if (n < 5) cout << "Vector underfilled." << endl;
            else {
                for (int i = 0; i < n; i++)
                    for (int j = 1; j < n - i; j++)
                        if (vec[j] < vec[j - 1]) swap(vec[j], vec[j - 1]);

                cout << "Fifth largest element = " << vec[4] << endl;

                cout << "{ ";
                for (int i = 0; i < n; i++)
                    cout << vec[i] << " ";
                cout << "}" << endl;

            }
        }
    }

    return 0;
}
