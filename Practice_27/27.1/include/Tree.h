#pragma once
#include "LargeBranch.h"
#include <iostream>
#include <cstdlib>

class Tree : public LargeBranch{
private:
        // Массив больших веток
    int largeSize;
    LargeBranch* largeBranch;

        // Массив для кол-ва эльфов по именно
    int counts[4] = {0, 0, 0, 0};

    // Метод, определяющий положение ветки (лево, середина или право)
    int branchPosition(int i) const;
public:
        // Конструктор: заполняет массив кол-вом имен эльфов
    Tree();
        // Метод. Сеттер: возвращает кол-во больших веток
     int getLargeSize() const;
        // Метод, отображающий кол-во эльфов на дереве по-именно
    void printNames();
        // Метод, графически отображающий ветки на дереве
    void picture();
        // Диструктор:  удвляет массив больших веток
    ~Tree();

};
