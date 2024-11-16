#include <fstream>
#include <iostream>

using namespace std;

int main() {
    cout << "\nTask  #2\n  Developing a Text File Viewer\n" << endl;

    int totalSize;

    ifstream textFile;
    if (!textFile.is_open())
        textFile.open("C:\\Users\\mikha\\Desktop\\SkillBox\\Practice 19\\19.2\\text.txt", ios::binary);
    textFile.seekg(0);
    totalSize = sizeof(textFile) - textFile.gcount();
    char buffer[totalSize];
    textFile.read(buffer, sizeof(buffer));
    buffer[totalSize - 1] = 0;
    textFile.close();

    cout << buffer << endl;
    return 0;
}
