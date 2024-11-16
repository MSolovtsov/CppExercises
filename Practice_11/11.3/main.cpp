#include <iostream>
#include <cmath>
using namespace std;


string assignmentStr(string totalStr){
    string numStr;
    for (int i = 0; i < totalStr.length(); i++){
        if (totalStr[i] != '.') {
            numStr += totalStr[i];
        } else break;
    }
    return numStr;
}

bool isCorrectPart (string totalStr){
    int numInt = 0;
    string numStr = assignmentStr(totalStr);
    for (int i = 0; i < numStr.length(); i++){
        numInt +=  (int)(numStr[i] - '0') * (int)pow(10, numStr.length() - 1 - i);
    }
    bool isCorrectNull = true;
    if (numStr.length() > 1 && numInt < 10) {
        numStr += '.';
        for (int i = 0; i < numStr.length(); i++) {
            if (numStr[i] == '0' && numStr[i + 1] != '.'){
                isCorrectNull = false;
                break;
            }
        }
    }
    return (numInt <= 255 && isCorrectNull);
}

string nextPartStr(string totalStr){
    string numStr = assignmentStr(totalStr);
    numStr += '.';
    string resStr;
    for (int i = 0; i < totalStr.length(); i++){
        if (numStr[i] != totalStr[i])
            resStr += totalStr[i];
    }
    return resStr;
}

int main() {
    cout << "\n#3  IP Address Validation.\n" << endl;

    cout << "Enter IPv4 (255.255.255.255):";
    string ipv4;
    cin >> ipv4;

    bool isNumber = true;
    int check = 0;
    for (int i = 0; i < ipv4.length(); i++) {
        if (isdigit(ipv4[i]) == 0 && ipv4[i] != '.') {
            isNumber = false;
            break;
        } else if (ipv4[i] == '.') check++;
    }

    if (!isNumber) cout << "Only numbers must be used." << endl;
    else {
        if ((ipv4.length() > 15 || ipv4.length() < 7) || check != 3)
            cout << "Incorrect IP entry." << endl;
        else {
            bool isIpNotation = true;
            for (int i = 0; i < check + 1; i++){
                if (!isCorrectPart(ipv4)){
                    isIpNotation = false;
                    break;
                }
                ipv4 = nextPartStr(ipv4);
            }
            if (!isIpNotation) cout << "Incorrect entry." << endl;
            else cout << "Correct IP address." << endl;
        }
    }
    return 0;
}
