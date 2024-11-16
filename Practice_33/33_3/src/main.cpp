#include <iostream>
#include <exception>
#include "List.h"

using namespace std;

int main() {
    cout << "\nTask  #3\n\tData register on templates\n" << endl;

    List<int, string>* list = new List<int, string>();

    // Вводим размер листа
    cout << "Enter size of List: ";
    int input;
    cin >> input;

    // Заполняем лист
    cout << "\tADD: " << endl;
    for (int i = 0; i < input; i++){
        cout << "-- enter value:";
        string _value;
        cin >> _value;
        list->add(i, _value);
    }
    cout << endl;
    list->print();

    // Удаляем элемент по ключу
    cout << "\tREMOVE:" << endl;
    cout << "Enter number of value:";
    cin >> input;
    list->remove(input);
    cout << endl;
    list->print();

    // Находим значениеэлемента по ключу
    cout << "\tFIND:" << endl;
    cout << "Enter number of value:";
    cin >> input;
    cout << endl;
    cout << list->find(input) << endl;

    delete list;
    return 0;
}
