#pragma once
#include "Branch.h"
#include <iostream>

using namespace std;

class ElfesNames {
private:
        // Список имен эльфов
    enum Names{
        Misha,
        Anton,
        Ilya,
        None
    };
        // Счетчик имен
    int size = (int)None + 1;
    int counts[4] = {0, 0, 0, 0};

public:
        // Метод, возвращающий имя стокой
    static string strNames(int intElf);
        // Метод, считающий кол-во имен эльфов на большой ветке
    void countNames(int intElf);
        // Метод, вызывающий кол-во возможных имен
    int getCountNames() const;
        // Метод. Геттер: возвращает число определенного имени на большой ветке
    int get_arrayCount(int i) const;

};

