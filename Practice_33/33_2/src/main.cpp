#include <iostream>
#include "Game.h"

using namespace std;

int main() {
    cout << "\nTask  #2\n\tFishing game\n" << endl;

    // Создаем игру
    Game* game = new Game();
    // Отображаем поле
    game->showFuild();

    cout << "\nYour move: ";
    try{
        game->movement();
    } catch (invalid_argument& i){
        cerr << "Sorry... " << i.what() << endl;
    } catch (runtime_error& r){
        cerr << "Congratulations! " << r.what() << endl;
    }

    delete game;
    return 0;
}
