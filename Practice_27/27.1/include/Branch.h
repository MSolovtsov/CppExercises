#pragma once
#include <iostream>
#include <string>

using namespace std;

class Branch {
private:
        // Имя эльфа на ветке
    string elfName;

public:
        // Метод. Сеттер: заполняет имя эльфа на ветке
    void setName(string inName);
        // Метод, возвращающий первую букву имени эльфа при наличии
    string pictureHead();



};
