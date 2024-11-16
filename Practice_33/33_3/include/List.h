#pragma once
#include <iostream>
#include <vector>
#include <exception>

using namespace std;

template<typename T_key, typename T_value>
class List {
private:
    struct Registry{
        T_key key;
        T_value value;
    };

    vector<Registry> mainList;

    // Выносит элемент num'ого положения в конец вектора и удаляет
    void deleteLine(int num);

    // Выводит сообщение, что лист - пустой
    void listIsEmpty();

public:

    // Добавляет элемент с ключом
    void add(T_key _key, T_value _value);

    // Удаляет элемент по ключу
    void remove(T_key _key);

    // Отображает все значения с ключами
    void print();

    // Находит значение элемента по ключу
    T_value find(T_key _key);

    // Деструктор - очищает вектор
    ~List();

};

