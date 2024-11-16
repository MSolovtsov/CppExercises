#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

vector<string> character_table(18);

void headPrint(){
    system("cls");
    cout << "\nTask  #4.\n  Implementation of a role-playing game\n" << endl;
}

enum action{
    move_up = 1,
    move_left = 2,
    move_down = 3,
    move_right = 4
};

struct point{
    int height = 0;
    int weight = 0;
};

struct math_vector{
    point start;
    point end;
    float distance = 0.f;
};

struct distance_to_enemies{
    math_vector toBad1;
    math_vector toBad2;
    math_vector toBad3;
    math_vector toBad4;
    math_vector toBad5;
};

distance_to_enemies main_distance;

struct character{
    int number_of_character = 0;
    string name = "Enemy #";
    bool isLive = true;
    int health = 0;
    int protection = 0;
    int damage = 0;
    point location;
};

character player;
character bad1;
character bad2;
character bad3;
character bad4;
character bad5;

void definition_distance(math_vector& vector){
    int height_delta = vector.end.height - vector.start.height;
    int weight_delta = vector.end.weight - vector.start.weight;
    vector.distance = (float)sqrt(pow(height_delta, 2) + pow(weight_delta, 2));
}

bool isNum(string& in){
    for (int i = 0; i < in.size(); i++)
        if (!isdigit(in[i])) return false;
    return true;
}

void secure_input(string& input){
    do {
        cin >> input;
        if (!isNum(input)) cout << "\tincorrect try again:";
    } while (!isNum(input));
}

void fillTheMainCharacter(character& main){
    string input;
    cout << "Welcome to the mini role playing game!" << endl;
    cout << "You have only three types of commands:" << endl;
    cout << "\'w\' \'a\' \'s\' \'d\' - Keyboard control" << endl;
    cout << "\'save\' - save the game" << endl;
    cout << "\'load\' - load the game" << endl;
    cout << "\nEnter character's name:";
    cin >> main.name;
    cout << "Enter " << main.name << "'s health:";
    secure_input(input);
    main.health = stoi(input);
    cout << "Enter " << main.name << "'s protection:";
    secure_input(input);
    main.protection = stoi(input);
    cout << "Enter " << main.name << "'s damage:";
    secure_input(input);
    main.damage = stoi(input);
    main.number_of_character = -1;
}

void fillTheBadCharacter(character& bad, int& number){
    bad.name += to_string(number + 1);
    bad.number_of_character = number + 1;
    bad.health = rand() % 150 + 50;
    bad.protection = rand() % 50;
    bad.damage = rand() % 30 + 15;
}

void assign_w_h(character& body, int& w, int& h){
    w = rand() % 21 + 1;
    h = rand() % 21 + 1;
    body.location.height = h;
    body.location.weight = w;
}

void assign_a_location (int* field, character& body, int& w, int& h, int& count){

    if (*(field + (22 * h + w)) == 0) {
        *(field + (22 * h + w)) = body.number_of_character;
    }
    else count--;
}

character* definition_of_bad(int number){
    switch (number){
        case 0:
            return &bad1;
        case 1:
            return &bad2;
        case 2:
            return &bad3;
        case 3:
            return &bad4;
        case 4:
            return &bad5;
    }
}

void fillPlayingField(int* field, bool isRandom = true){
    for (int i = 0; i < 22; i++) {
        for (int j = 0; j < 22; j++) {
            if (i == 0 || i == 21 || j == 0 || j == 21)
                *(field + (22 * i + j)) = -2;
            else
                *(field + (22 * i + j)) = 0;
        }
    }

    int w;
    int h;
    for (int i = 0; i < 5; i++){
        if (isRandom) {
            assign_w_h(*definition_of_bad(i), w, h);
            fillTheBadCharacter(*definition_of_bad(i), i);
        } else {
            w = definition_of_bad(i)->location.weight;
            h = definition_of_bad(i)->location.height;
        }

        assign_a_location(field, *definition_of_bad(i), w, h, i);

    }

    for (int i = 0; i < 1; i++) {
        if (isRandom)
            assign_w_h(player, w, h);
        else {
            w = player.location.weight;
            h = player.location.height;
        }
        assign_a_location(field, player, w, h, i);
    }
}

string display(int& num){
    switch (num){
        case 0:
            return ". ";
        case -1:
            return "P ";
        case -2:
            return "  ";
        default:
            return "E" + to_string(num);
    }
}

void update_character_table(character& body, int count = 0){
    //
    character_table[0 + count] += "   | \t" + body.name;
    character_table[1 + count] += "   |_____________________";
    character_table[2 + count] += "   | health \t= " + to_string(body.health);
    character_table[3 + count] += "   | protection \t= " + to_string(body.protection);
    character_table[4 + count] += "   | damage \t= " + to_string(body.damage);
    character_table[5] = " ";
}

void OutPutPlaingField(int* field){
    for (int i = 0; i < 22; i++) {
        for (int j = 0; j < 22; j++)
            cout << " " << display(*(field + (22 * i + j)));
        if (i < character_table.size())
            if (!character_table[i].empty())
                cout << "   " << character_table[i];
        cout << endl;
    }
}

action keyboard_to_action_converter(char& keyboard){
    switch (keyboard) {
        case 'w':
            return move_up;
        case 'a':
            return move_left;
        case 's':
            return move_down;
        case 'd':
            return move_right;
    }
}

math_vector *definition_of_distance(int num) {
    switch (num){
        case 0:
            return &main_distance.toBad1;
        case 1:
            return &main_distance.toBad2;
        case 2:
            return &main_distance.toBad3;
        case 3:
            return &main_distance.toBad4;
        case 4:
            return &main_distance.toBad5;
    }
}

void clearTheCharacter(character& body){
    body.isLive = false;
    body.health = 0;
    body.damage = 0;
    definition_of_distance(body.number_of_character - 1)->distance = 0;
}

void attack(int* field, character& attacker, character& sufferer){
    sufferer.protection -= attacker.damage;
    if (sufferer.protection < 0){
        sufferer.health += sufferer.protection;
        sufferer.protection = 0;
    }
    if (sufferer.health <= 0) {
        *(field + (22 * sufferer.location.height + sufferer.location.weight)) = 0;
        clearTheCharacter(sufferer);
    }
}

action move_for_bad_gay(){
    int num;
    num = rand() % 4 + 1;
    return (action)num;
}

void up_point(int* field, character& body){
    *(field + (22 * body.location.height + body.location.weight)) = 0;
    body.location.height--;
    *(field + (22 * body.location.height + body.location.weight)) = body.number_of_character;
}

void left_point(int* field, character& body){
    *(field + (22 * body.location.height + body.location.weight)) = 0;
    body.location.weight--;
    *(field + (22 * body.location.height + body.location.weight)) = body.number_of_character;
}

void down_point(int* field, character& body){
    *(field + (22 * body.location.height + body.location.weight)) = 0;
    body.location.height++;
    *(field + (22 * body.location.height + body.location.weight)) = body.number_of_character;
}

void right_point(int* field, character& body){
    *(field + (22 * body.location.height + body.location.weight)) = 0;
    body.location.weight++;
    *(field + (22 * body.location.height + body.location.weight)) = body.number_of_character;
}

void player_step(int* field, character& body, int& next_pos){
    if (next_pos == -2) {
        cout << "\thit the border!\n";
    } else {
        attack(field, body, *definition_of_bad(next_pos - 1));
    }
}

void make_a_step(int *field, character &body, action step, bool isActive = false) {
    int next_position;
        switch (step) {
            case move_up:
                next_position = *(field + (22 * (body.location.height - 1) + body.location.weight));
                if (next_position == 0) {
                    up_point(field, body);
                } else {
                    if (!isActive) {
                        if (next_position != -1) {
                            *(field + (22 * body.location.height + body.location.weight)) = 0;
                            make_a_step(field, body, move_for_bad_gay());
                        } else
                            attack(field, body, player);

                    } else
                        player_step(field, body, next_position);

                }
                break;

            case move_left:
                next_position = *(field + (22 * body.location.height + (body.location.weight - 1)));
                if (next_position == 0) {
                    left_point(field, body);
                } else {
                    if (!isActive) {
                        if (next_position != -1) {
                            *(field + (22 * body.location.height + body.location.weight)) = 0;
                            make_a_step(field, body, move_for_bad_gay());
                        } else
                            attack(field, body, player);

                    } else
                        player_step(field, body, next_position);

                }
                break;

            case move_down:
                next_position = *(field + (22 * (body.location.height + 1) + body.location.weight));
                if (next_position == 0) {
                    down_point(field, body);
                } else {
                    if (!isActive) {
                        if (next_position != -1) {
                            *(field + (22 * body.location.height + body.location.weight)) = 0;
                            make_a_step(field, body, move_for_bad_gay());
                        } else
                            attack(field, body, player);

                    } else
                        player_step(field, body, next_position);

                }
                break;

            case move_right:
                next_position = *(field + (22 * body.location.height + (body.location.weight + 1)));
                if (next_position == 0) {
                    right_point(field, body);
                } else {
                    if (!isActive) {
                        if (next_position != -1) {
                            *(field + (22 * body.location.height + body.location.weight)) = 0;
                            make_a_step(field, body, move_for_bad_gay());
                        } else
                            attack(field, body, player);

                    } else
                        player_step(field, body, next_position);

                }
                break;
        }
}

bool isChar(string& com){
    if (com.size() == 1)
        for (int i = 0; i < com.size(); i++)
            if (com[i] == 'w' ||com[i] == 'a' || com[i] == 's' || com[i] == 'd')
                return true;
    return false;

}

bool isOtherCommand(string& com, bool isSave = true){
    string word;
    word = (isSave) ? "save" : "load";
    if (com.size() == 4)
        for (int i = 0; i < com.size(); i++)
            if (com[i] == word[i])
                return true;
    return false;
}

void fillTheSave(ofstream& file, character& body){

    file.write((char*)&body.number_of_character, sizeof(body.number_of_character));

    int len = body.name.size();
    file.write((char*)&len, sizeof(len));
    file.write(body.name.c_str(), len);

    file.write((char*)&body.isLive, sizeof(body.isLive));
    file.write((char*)&body.health, sizeof(body.health));
    file.write((char*)&body.protection, sizeof(body.protection));
    file.write((char*)&body.damage, sizeof(body.damage));

    file.write((char*)&body.location.height, sizeof(body.location.height));
    file.write((char*)&body.location.weight, sizeof(body.location.weight));

}

void loadTheSave(ifstream& file, character& body){

    file.read((char*)&body.number_of_character, sizeof(body.number_of_character));

    int len;
    file.read((char*)&len, sizeof(len));
    body.name.resize(len);
    string account;
    file.read((char*)body.name.c_str(), len);

    file.read((char *) &body.isLive, sizeof(body.isLive));
    file.read((char *) &body.health, sizeof(body.health));
    file.read((char *) &body.protection, sizeof(body.protection));
    file.read((char *) &body.damage, sizeof(body.damage));

    file.read((char *) &body.location.height, sizeof(body.location.height));
    file.read((char *) &body.location.weight, sizeof(body.location.weight));
}

void control_block(int* field, ifstream& fileRead, ofstream& fileWrite){
    string command;
    bool isControl = false;
    bool isSave = false;
    bool isLoad = false;
    cout << "\ncommand:";
    do {
        cin >> command;
        isControl = isChar(command);
        isSave = isOtherCommand(command);
        isLoad = isOtherCommand(command, false);
        if (!(isControl || isSave || isLoad)) cout << "\tincorrect\n";
    } while (!(isControl || isSave || isLoad));

    if (isControl){
        make_a_step(field, player, keyboard_to_action_converter(command[0]), true);
    } else if (isSave){
        fileWrite.open("Save.bin", std::ios::binary);
        if (fileWrite.is_open()) {
            fillTheSave(fileWrite, player);
            for (int i = 0; i < 5; i++)
                fillTheSave(fileWrite, *definition_of_bad(i));
            fileWrite.close();
        }
    } else {
        fileRead.open("Save.bin");
        if (fileRead.is_open()) {
            if (!fileRead.eof()) {
                loadTheSave(fileRead, player);
                    for (int i = 0; i < 5; i++)
                        loadTheSave(fileRead, *definition_of_bad(i));
                    fillPlayingField(field, false);
            }
            fileRead.close();
        }
    }
}

void distance_monitoring(character& bad, int& num){
        definition_of_distance(num)->start.height = player.location.height;
        definition_of_distance(num)->start.weight = player.location.weight;
        definition_of_distance(num)->end.height = bad.location.height;
        definition_of_distance(num)->end.weight = bad.location.weight;
        definition_distance(*definition_of_distance(num));

}

void clear_table(){
    character_table.clear();
    character_table.resize(18);
}

void game(int* field, ifstream& fileRead, ofstream& fileWrite){
    bool youLose = true;
    bool youWin = true;
    do {
        headPrint();
        OutPutPlaingField(field);
        clear_table();
        control_block(field, fileRead, fileWrite);
        int count = 0;
        for (int i = 0; i < 5; i++) {

            if (definition_of_bad(i)->isLive) {
                make_a_step(field, *definition_of_bad(i), move_for_bad_gay());
                distance_monitoring(*definition_of_bad(i), i);

                if (definition_of_distance(i)->distance <= (float) sqrt(5)
                        && definition_of_distance(i)->distance != 0) {
                    if (count == 2)
                        count = 0;
                    count++;

                    update_character_table(*definition_of_bad(i), 6 * count);
                }
            }
        }
        update_character_table(player);
        youLose = bad1.isLive + bad2.isLive + bad3.isLive + bad4.isLive + bad5.isLive;
        youWin = player.isLive;
    } while (youLose && youWin);

    headPrint();
    cout << ((youWin) ? "You WIN!!!" : "You LOSE...") << endl;

}

int main() {
    headPrint();
    srand(time(nullptr));

    ifstream saveRead;
    ofstream saveWrite;

    fillTheMainCharacter(player);
    clear_table();
    update_character_table(player);
    int field[22][22];
    fillPlayingField(*field);
    game(*field, saveRead, saveWrite);

    return 0;
}
