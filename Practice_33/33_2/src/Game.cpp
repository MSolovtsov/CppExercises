#include "Game.h"

// Заполняет поле нулями
void Game::fillZeroFuild(){
    for (int i = 0; i < 9; i++){
        this->fuild[i] = Zero;
    }
}

// Заполнение персонажа
void Game::pointCharacter(bool isFish = true){
    Character character = (isFish) ? Fish : Boot;

    int point = std::rand() % 9;

    if (this->fuild[point] == Zero)
        this->fuild[point] = character;
    else
        pointCharacter(isFish);
}

// Конструктор - заполняет игровое поле с персонажами
Game::Game(){
    srand(time(nullptr));
    fillZeroFuild();

    pointCharacter();
    for (int i = 0; i < 3; i++)
        pointCharacter(false);
}

// Отображает игровое поле
void Game::showFuild(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << "\t" << 1 + j + i*3;
        }
        cout << endl;
    }
}

// Ход
void Game::movement(){
    int course;
    cin >> course;
    if (this->fuild[course - 1] == Fish) throw runtime_error("You WON!");
    else if (this->fuild[course - 1] == Boot) throw invalid_argument("You LOSE!");
    else {
        cout << "Empty! Try again: ";
        movement();
    }
}

// Деструктор - обнуляет поле
Game::~Game(){
    for(int i = 0; i < 9; i++)
        this->fuild[i] = Zero;
}