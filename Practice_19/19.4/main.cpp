#include <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "\nTask  #4\n  PNG detector development\n" << endl;

    bool isPNG = true;
    char generalCap[4];

    fstream image;

//    image.open("C:\\Users\\mikha\\Desktop\\SkillBox\\Practice 19\\19.4\\buf\\Misha2.0.png", ios::binary);
    image.open(R"(C:\Users\mikha\Desktop\SkillBox\Practice 19\19.4\buf\Misha2.0.png)");
    cout << image.is_open() << endl;
    image.seekg(0);
    image.read(generalCap, sizeof(generalCap));
    image.flush();

    for (int i = 0; i < 4; i++)
        cout << generalCap[i] << endl;

    if (generalCap[0] != -119) {
        isPNG = false;
    } else {
        if (generalCap[1] != 'P' || generalCap[2] != 'N' || generalCap[3] != 'G') isPNG = false;
    }
    image.close();

    cout << "is" << (isPNG ? " " : " not ") << "PNG image" << endl;

    return 0;
}
