#include <iostream>
#include <sstream>

using namespace std;

bool compare (double value, double reference, double epsilon){
    return  (value >= reference - epsilon) && (value <= reference + epsilon);
}

int main() {
    cout << "\n#3  Calculator\n" << endl;

    string inputMathOperation;
    cout << "Enter math operation:\n";
    cin >> inputMathOperation;
    stringstream temp_stream(inputMathOperation);

    double numFirst;
    double numSecond;
    char operation;
    temp_stream >> numFirst >> operation >> numSecond;

    double result = 0.;
    bool isPrint = true;
    if (operation == '+') result = numFirst + numSecond;
    else if (operation == '-') result = numFirst - numSecond;
    else if (operation == '*') result = numFirst * numSecond;
    else if (operation == '/') {
        if (compare(numSecond, 0, 0.01)) {
            cout << "Can't divide by zero." << endl;
            isPrint = false;
        }
        else
            result = numFirst / numSecond;
    }
    else {
        cout << "Wrong operation" << endl;
        isPrint = false;
    }

    if (isPrint) {
        char resultChar[1];
        string resultStr = "Result = ";
        sprintf(resultChar, "%.2f",result);
        resultStr += resultChar;
        cout << resultStr << endl;
    }
    return 0;
}
