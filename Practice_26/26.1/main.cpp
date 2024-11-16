#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

class Track{
public:
    string name;
    tm date;
    time_t duration;

};

Track tracks[5];
int size = 5;

class Player{
private:
    Track music;
    int numberInLine = -1;
    bool isPaused = false;

    void clearTrack(){
        music.name = "";
        music.duration = time(nullptr);
        music.date = *localtime(&music.duration);
        numberInLine = -1;
    }

public:

    void play(){
        if (!isPaused) {
            string song;
            cout << "Enter track name:";
            cin >> song;

            if (music.name.empty()) {
                for (int i = 0; i < size; i++)
                    if (tracks[i].name == song) {
                        music = tracks[i];
                        numberInLine = i;
                        break;
                    }
            } else cout << "\timpossible!" << endl;
        }
        cout << music.name << " is playing" << endl;
        isPaused = false;
    }

    void pause(){
        if (!music.name.empty()) {
            if (!isPaused) {
                isPaused = true;
                cout << music.name << " was paused" << endl;
            } else
                cout << music.name << " already on pause" << endl;
        } else {
            cout << "track not selected" << endl;
            play();
        }
    }

    void next(){
        if (!music.name.empty()){
            if (numberInLine != size - 1)
                numberInLine++;
            else
                numberInLine = 0;

            music = tracks[numberInLine];
            cout << "The next song is " << music.name << endl;
        } else {
            cout << "track not selected" << endl;
            play();
        }
    }

    void stop(){
        if (!music.name.empty()) {
            cout << music.name << " was stopped" << endl;
            clearTrack();
        } else {
            cout << "track not selected" << endl;
            play();
        }
    }
};

int main() {
    cout << "\nTask #1\n  Implementing a simulated audio player\n" << endl;

    cout << "Fill the player:" << endl;
    for(int i = 0; i < size; i++){
        cout << "Track name:";
        cin >> tracks[i].name;
        cout << "Release year (YYYY.mm.dd):";
        cin >> get_time(&tracks[i].date, "%Y.%m.%d");
        cout << "Duration of the recording (in sec):";
        cin >> tracks[i].duration;
        cout << "--------------------------------\n" << endl;
    }

    Player player;

    cout << "You have commands:" << endl;
    cout << "\tplay\n\tpause\n\tnext\n\tstop\n\texit\n" << endl;
    string command = "play";
    do {

        if (command == "play")
            player.play();
        else if (command == "pause")
            player.pause();
        else if (command == "next")
            player.next();
        else if (command == "stop")
            player.stop();
        else if (command != "exit")
            cout << "\tincorrect command!" << endl;

        cout << "--------------------------------\n" << endl;
        cout << "Enter command:";
        cin >> command;
    } while (command != "exit");

    return 0;
}

