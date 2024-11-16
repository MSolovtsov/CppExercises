#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "\nTask  #1\n" << endl;

    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int maxSum = 0;
    int i_ind, j_ind;
    int sum = 0;


//    int start = 0;
//    int end = 0;
//    int size = 1;
//    for (int j = 0; j < a.size(); j++){
//        for (int i = start; i < a.size() - end; i++) {
//
//            for (int s = i - start; s < i - start + size; s++)
//                sum += a[s];
//
//            if (sum > maxSum){
//                maxSum = sum;
//                sum = 0;
//                i_ind = i - start;
//                j_ind = i + end;
//            }
//        }
//        if (j % 2 == 0) start++;
//        else end++;
//
//        size++;
//    }

//#1
    for (int i = 0; i < a.size(); i++){
        if (a[i] > maxSum){
            maxSum = a[i];
            i_ind = i;
            j_ind = i;
        }
    }
//#2
    for (int i = 1; i < a.size(); i++){
        if (a[i - 1] + a[i] > maxSum){
            maxSum = a[i - 1] + a[i];
            i_ind = i - 1;
            j_ind = i;
        }
    }
//#3
    for (int i = 1; i < a.size() - 1; i ++){
        if (a[i - 1] + a[i] + a[i + 1] > maxSum){
            maxSum = a[i - 1] + a[i] + a[i + 1];
            i_ind = i - 1;
            j_ind = i + 1;
        }
    }
//#4
    for (int i = 2; i < a.size() - 1; i ++){
        if (a[i - 2] + a[i - 1] + a[i] + a[i + 1] > maxSum){
            maxSum = a[i - 2] + a[i - 1] + a[i] + a[i + 1];
            i_ind = i - 2;
            j_ind = i + 1;
        }
    }
//#5
    for (int i = 2; i < a.size() - 2; i ++){
        if (a[i - 2] + a[i - 1] + a[i] + a[i + 1] + a[i + 2] > maxSum){
            maxSum = a[i - 2] + a[i - 1] + a[i] + a[i + 1] + a[i + 2];
            i_ind = i - 2;
            j_ind = i + 2;
        }
    }
//#6
    for (int i = 2; i < a.size() - 2; i ++){
        if (a[i - 2] + a[i - 1] + a[i] + a[i + 1] + a[i + 2] > maxSum){
            maxSum = a[i - 2] + a[i - 1] + a[i] + a[i + 1] + a[i + 2];
            i_ind = i - 2;
            j_ind = i + 2;
        }
    }
//#7
    for (int i = 3; i < a.size() - 2; i ++){
        if (a[i - 3] + a[i - 2] + a[i - 1] + a[i] + a[i + 1] + a[i + 2] > maxSum){
            maxSum = a[i - 3] + a[i - 2] + a[i - 1] + a[i] + a[i + 1] + a[i + 2];
            i_ind = i - 3;
            j_ind = i + 2;
        }
    }
//#8
    for (int i = 3; i < a.size() - 3; i ++){
        if (a[i - 3] + a[i - 2] + a[i - 1] + a[i] + a[i + 1] + a[i + 2] + a[i + 3] > maxSum){
            maxSum = a[i - 3] + a[i - 2] + a[i - 1] + a[i] + a[i + 1] + a[i + 2] + a[i + 3];
            i_ind = i - 3;
            j_ind = i + 3;
        }
    }
//#9
    for (int i = 4; i < a.size() - 3; i ++){
        if (a[i - 4] + a[i - 3] + a[i - 2] + a[i - 1] + a[i] + a[i + 1] + a[i + 2] + a[i + 3] > maxSum){
            maxSum = a[i - 3] + a[i - 2] + a[i - 1] + a[i] + a[i + 1] + a[i + 2] + a[i + 3];
            i_ind = i - 4;
            j_ind = i + 3;
        }
    }


    cout << "Max sum = " << maxSum << "  [" << i_ind << "; " << j_ind << "] " << endl;

    return 0;
}
