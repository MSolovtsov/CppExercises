//#include "../include/disk.h"
#include "../include/ram.h"
#include <fstream>
#include <iostream>

void save(){
    ofstream file;
    file.open("data.txt");
    if (file.is_open()){
            for(int i = 0; i < 8; i++){
                int value;
                read(value, i);
                file << value << endl;
            }

    } else cout << "impossible to save" << endl;
    file.close();
    cout << "saved successfully" << endl;
}

void load(){
    ifstream file;
    file.open("data.txt");
    if (file.is_open()){
        if (!file.eof()){
            for (int i = 0; i < 8; i++){
                int value;
                file >> value;
                write(value, i);
            }
        } else cout << "not found";
    } else cout << "impossible to load" << endl;
    file.close();
    cout << "uploaded successfully" << endl;
}