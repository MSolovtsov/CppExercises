#pragma once
#include "Branch.h"
#include "ElfesNames.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class LargeBranch : public Branch , public ElfesNames{
private:
        // Массив маленьких веток
    int smallSize;
    Branch* smallBranches;

        // Массив для графического отображения ветви из пяти строк
    string pictureLargeBranch[7];

    // Метод, заполняющий графического массива ветви
    void pictureBranch();

public:
        // Конструктор: рандомно дает имена проживающим на маленьких ветках ельфам
            // && заполняет графический массив ветви
    LargeBranch();
        // Метод, возвращающий i-тую строку графического массива
    string getPictureBranch(int i);
        // Метод, дорисовывающий корни массива ветви
    void branchRoots(int pos);
        // Деструктор: удаляет массив маленьких веток
    ~LargeBranch();

};

