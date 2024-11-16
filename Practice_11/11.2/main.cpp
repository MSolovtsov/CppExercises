#include <iostream>

using namespace std;

bool isCorrrectPart(string emailStr){
    if (emailStr.length() > 64) return false;
    if (emailStr[0] == '.') return false;
    for (int i = 0; i < emailStr.length(); i++){
        if (emailStr[i] == '.' && emailStr[i] == emailStr[i+1]) return false;
    }
    return true;
}

bool isCorrectTotal(bool isCorrect, string emailString){
    if (!isCorrect) return false;
    int check = 0;
    for (int i = 0; i < emailString.length(); i++){
        if (emailString[i] == '.') check++;
        if ((emailString[i] < 'a' || emailString[i] > 'z') && emailString[i] != '.') return false;
    }
    if (check != 1) return false;
    if (emailString[emailString.length()-1] == '.') return false;
    return true;
}
int main() {
    cout << "\n#2  Checking the correctness of the email address\n" << std::endl;

    cout << "Enter your email address:";
    string email;
    cin >> email;

    string emailFirst;
    string emailSecond;

    for (int i = 0; i < email.length(); i++){
        if (email[i] != '@')
            emailFirst += email[i];
        else break;
    }

    if (emailFirst.length() == email.length()) {
        cout << "Incorrect email entry\n";
        return -1;
    }
    for ( int i = emailFirst.length() + 1; i < email.length(); i++)
        emailSecond += email[i];

    cout << "---------------------------\n";
    if (isCorrrectPart(emailFirst) && isCorrectTotal(isCorrrectPart(emailSecond), emailSecond)) cout << "Everything is correct." << endl;
    else if (!isCorrrectPart(emailFirst)) cout << "There is an invalid character." << endl;
    else if (!isCorrectTotal(isCorrrectPart(emailSecond), emailSecond)) cout << "There is an invalid character in the second part." << endl;

    return 0;
}
