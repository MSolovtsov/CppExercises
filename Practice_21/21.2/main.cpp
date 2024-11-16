#include <iostream>
#include <vector>

using namespace std;

enum room_type {
    bedroom = 1,
    kitchen = 2,
    bathroom = 3,
    nursery = 4,
    living = 5
};

struct room {
    room_type name = bedroom;
    float space = 0.f;
};

struct mainBuilding {
    int number_of_floors = 1;
    int number_of_rooms = 2;
    float height = 0.f;
    float space = 0.f;
    vector<vector<room>> houseful;
};

struct secondBuilding {
    bool isPresent = false;
    float space = 0.f;
    float height = 0.f;
};

struct cottage_area {
    mainBuilding house;
    secondBuilding barn;
    secondBuilding bathhouse;
};

string number_endings(int& num){
    string number = to_string(num + 1);
    switch (num) {
        case 0:
            number += "st";
            break;
        case 1:
            number += "nd";
            break;
        case 2:
            number += "rd";
            break;
        default:
            number += "th";
            break;
    }
    return number;
}

room_type enumeration_of_rooms(){
    cout << "\t1. Bedroom" << endl;
    cout << "\t2. Kitchen" << endl;
    cout << "\t3. Bathroom" << endl;
    cout << "\t4. Nursery" << endl;
    cout << "\t5. Living room" << endl;
    int number = 0;
    do {
        cin >> number;
        if (number < 1 || number > 5) cout << "incorrect!\n";
    } while (number < 1 || number > 5);
    room_type room;
    room = (room_type)number;
    return room;
}

string enum_to_string(room_type room){
    string word;
    switch (room) {
        case 1:
            word = "Bedroom";
            break;
        case 2:
            word = "Kitchen";
            break;
        case 3:
            word = "Bathroom";
            break;
        case 4:
            word = "Nursery";
            break;
        case 5:
            word = "Living room";
            break;
    }
    return word;
}

int determine_floors(){
    int floors;
    do {
        cout << "Number of floors:";
        cin >> floors;
        if (floors < 1 || floors > 3) cout << "\tincorrect!\n";
    } while (floors < 1 || floors > 3);
    return floors;
}

int determine_rooms(){
    int rooms;
    do {
        cout << "Number of room in floor:";
        cin >> rooms;
        if (rooms < 2 || rooms > 4) cout << "\tincorrect!\n";
    } while (rooms < 2 || rooms > 4);
    return rooms;
}

float determine_space(){
    float space;
    do {
        cin >> space;
        if (space <= 0.f) cout << "\tYou either have a room or you don't." << endl;
        else if (space > 30.f) cout << "\ttoo big for a village..." << endl;
    } while (space <= 0.f || space > 30.f);
    return space;
}

float determine_hight(){
    float hight;
    do {
        cin >> hight;
        if (hight <= 1.8f) cout << "\ttoo low" << endl;
        else if (hight > 3.f) cout << "\ttoo high" << endl;
    } while (hight <= 1.8f || hight > 3.f);
    return hight;
}

void fillTheMainBuilding(cottage_area& area){
    area.house.number_of_floors = determine_floors();
    area.house.number_of_rooms = determine_rooms();
    cout << "Floor height:";
    area.house.height = determine_hight();

    area.house.houseful.assign(area.house.number_of_floors, vector<room>(area.house.number_of_rooms));
    for (int i = 0; i < area.house.number_of_floors; i++) {
        cout << "Filling "<< to_string(i + 1) << " floor:" << endl;
        for (int j = 0; j < area.house.number_of_rooms; j++) {
            cout << number_endings(j) << " room is ..." << endl;
            area.house.houseful[i][j].name = enumeration_of_rooms();
            cout << enum_to_string(area.house.houseful[i][j].name) << " area:";
            area.house.houseful[i][j].space = determine_space();
            area.house.space += area.house.houseful[i][j].space;
        }
    }
}

void parameters_of_the_second_building(secondBuilding& build){
    cout << "height:";
    build.height = determine_hight();
    cout << "space:";
    build.space = determine_space();
}

void fillTheSecondBuildimng(cottage_area& area, bool isBarn){
    int flag;
    string word;
    if (isBarn) word = "barn";
    else word = "bathhouse";
    cout << "Do you need a " << word << " for this area?"
            "\n\t\"0\" - No"
            "\n\t\"1\" - Yes" << endl;
    do {
        cin >> flag;
        if (flag != 0 && flag != 1) cout << "\tincorrect!\n";
    } while (flag != 0 && flag != 1);

    if (isBarn && flag == 1) area.barn.isPresent = true;
    else if (!isBarn && flag == 1) area.bathhouse.isPresent = true;

    if (isBarn) {
        if (area.barn.isPresent)
            parameters_of_the_second_building(area.barn);

    } else {
        if (area.bathhouse.isPresent)
            parameters_of_the_second_building(area.bathhouse);
    }

}

void filling_cottege_area(cottage_area& area){
    fillTheMainBuilding(area);
    fillTheSecondBuildimng(area, true);
    fillTheSecondBuildimng(area, false);
}

void display_cottege_area(cottage_area& area){
    cout << "\tMain Building" << endl;
    cout << "Number of floors = " << area.house.number_of_floors << endl;
    cout << "Number of rooms per floor = " << area.house.number_of_rooms << endl;
    for (int i = 0; i < area.house.number_of_floors; i++)
        for (int j = 0; j < area.house.number_of_rooms; j++)
            cout << number_endings(j) << " - " << enum_to_string(area.house.houseful[i][j].name) << endl;
    cout << "Total area of the house = " << area.house.space << " m^2" << endl;
    cout << "Height of each floor = " << area.house.height << " m" << endl;

    cout << "\n\tBarn" << endl;
    if (area.barn.isPresent){
        cout << "Area = " << area.barn.space << " m^2" << endl;
        cout << "Height = " << area.barn.height << " m" << endl;
    } else cout << "NONE" << endl;

    cout << "\n\tBathhouse" << endl;
    if (area.bathhouse.isPresent){
        cout << "Area = " << area.bathhouse.space << " m^2" << endl;
        cout << "Height = " << area.bathhouse.height << " m" << endl;
    } else cout << "NONE" << endl;

}

void village_accounting(vector<cottage_area>& village, bool isInput = true) {
    string headword;
    headword = (isInput) ? "Filling" : "Display";

    cout << "=================================\n";
    cout << "|\t" << headword <<" the village\t|" << endl;
    cout << "=================================\n";
    for (int i = 0; i < village.size(); i++){
        cout << "|  \t" << number_endings(i) << "\tsection  \t|" << endl;
        cout << "---------------------------------" << endl;
        (isInput) ? filling_cottege_area(village[i]) : display_cottege_area(village[i]);
        cout << "---------------------------------" << endl;
    }
}

int main() {
    cout << "\nTask  #2.\n  Data model for the village\n" << endl;

    cout << "How many plots in the village?" << endl;
    int plots;
    cin >> plots;
    vector<cottage_area> village(plots);

    village_accounting(village);
    village_accounting(village, false);

    return 0;
}
