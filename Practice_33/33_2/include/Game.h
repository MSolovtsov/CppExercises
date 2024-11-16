#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

using namespace std;

class Game {
private:
    // Положения
    enum Character{
        Boot = -1,
        Zero = 0,
        Fish = 1
    };

    // Игровое поле
    Character fuild[9];

    // Заполняет поле нулями
    void fillZeroFuild();

    // Заполнение персонажа
    void pointCharacter(bool isFish);

public:
    // Конструктор - заполняет игровое поле с персонажами
    Game();

    // Отображает игровое поле
    void showFuild();

    // Ход
    void movement();

    // Деструктор - обнуляет поле
    ~Game();
};
