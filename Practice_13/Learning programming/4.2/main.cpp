#include <iostream>
#include <vector>

using namespace std;

int enter_num (int number){
    cout << "\tenter number of robot:";
    cin >> number;

    return number;
}

vector<int> leaving_at_the_end (vector<int> vec, int index){
    int pocket = vec[index];
    for (int i = index; i < vec.size() - 1; i++ )
         vec[i] = vec[i + 1];
    vec[vec.size() - 1] = pocket;

    return vec;
}

void print(vector<int> vec){
    cout << "{ ";
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "}" << endl;
}

int main() {
    vector<int> robots;

    cout << "Enter in descending order." << endl;
    int num = 0;
    while(num != -1){
        num = enter_num(num);
        robots.push_back(num);
    }


    cout << "\nand the last one" << endl;
    num = enter_num(num);

    if (robots.size() > 1)
        for (int i = 0; i < robots.size() ; i++)
            if (num >= robots[i]){
                robots = leaving_at_the_end(robots, i);
                robots.pop_back();
                i--;
            }


    robots.push_back(num);

    print(robots);

    return 0;
}
