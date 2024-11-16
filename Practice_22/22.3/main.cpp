#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool isAnagrama(map<string, string>::iterator word){
    vector<char> difference;

    for (int i = 0; i < word->first.size(); i++){
        if (i == 0) difference.push_back(word->first[i]);
        else
            for(int j = 0; j < difference.size(); j++){
                if (word->first[i] != difference[j])
                    difference.push_back(word->first[i]);
                else break;
            }
    }

    for (int i = 0; i < word->second.size(); i++) {
        if (word->second[i] != ' ') {
            for (int j = 0; j < difference.size() - 1; j++) {
                if (word->second[i] == difference[j])
                    break;
                else if (i == difference.size() - 2 && word->second[i] != difference[difference.size() - 1])
                    return false;
            }
        }
    }


    return true;
}

int main() {
    cout << "\nTask #3\n  Anagrams\n" << endl;

    map<string, string> words;
    pair<string, string> anagrams;
    cout << "enter first word:";
    getline(cin, anagrams.first);
    cout << "second word:";
    getline(cin, anagrams.second);
    words.insert(anagrams);
    cout << ((isAnagrama(words.begin()) ? "Yes, they are." : "No, they aren't.")) << endl;

    return 0;
}
