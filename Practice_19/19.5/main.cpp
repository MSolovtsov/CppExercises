#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void enterNumberOfQestion(int& num, const bool* isNew){
    string inputNum;
    bool isCorrect = true;
    do {
        cout << "Enter positive number (1 - 13):";
        cin >> inputNum;
        for (int i = 0; i < inputNum.size(); i++)
            if (!isdigit(inputNum[i])){
                isCorrect = false;
                break;
            }
        if (isCorrect){
            num = stoi(inputNum);
        } else {
            cout << "\tis not a number." << endl;
            num = -1;
        }
        isCorrect = true;
    } while (num <= 0);

    while (num > 13){
        num -= 13;
    }

    bool isRight = false;
    while (!isRight){
        if (!*(isNew + num - 1)){
            if (num + 1 <= 13) num++;
            else num = 1;
        }
        else isRight = true;
    }
}

int main() {
    cout << "\nTask  #5\n  Implementation of the game 'What? Where? When?'\n" << endl;

    ifstream question;
    ifstream answer;
    int numOfQest = 0;
    int games = 13;
    string inQuestion;
    string inAnswer;
    string myAnswer;
    bool isNewQuestion[13];

    int viewershipScores = 0;
    int connoisseurScores = 0;

    for (int i = 0; i < 13; i++)
        isNewQuestion[i] = true;

    while (games > 0) {
        enterNumberOfQestion(numOfQest, isNewQuestion);
        isNewQuestion[numOfQest - 1] = false;

        question.open(R"(C:\Users\mikha\Desktop\SkillBox\Practice 19\19.5\questions.txt)");
        question.seekg(0);
        for (int i = 0; i < numOfQest; i++){
            inQuestion = "";
            getline(question, inQuestion);
        }
        question.close();

        cout << "Attention, the question:\n\t" << inQuestion << endl;
        cout << "An answer:\n";
        cin >> myAnswer;

        answer.open(R"(C:\Users\mikha\Desktop\SkillBox\Practice 19\19.5\answers.txt)");
        for (int i = 0; i < numOfQest; i++){
            inAnswer = "";
            getline(answer, inAnswer);
        }
        answer.close();

        bool isWin = true;
        if (myAnswer.size() != inAnswer.size()) isWin = false;
        else {
            for (int i = 0; i < inAnswer.size(); i++)
                if (myAnswer[i] != inAnswer[i]){
                    isWin = false;
                    break;
                }
        }

        if (isWin){
            cout << "+ score for connoisseurs!" << endl;
            connoisseurScores++;
        } else {
            cout << "+ score for viewership!" << endl;
            viewershipScores++;
        }

        cout << "Scores:" <<"\n\tConnoisseurs: " << connoisseurScores << "\n\tViewership: " << viewershipScores << "\n" << endl;
        games--;
    }

    cout << (connoisseurScores > viewershipScores ? "Connoisseurs " : "Viewership ") << "WIN!" << endl;
    return 0;
}
