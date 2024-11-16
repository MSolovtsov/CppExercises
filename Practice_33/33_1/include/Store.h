#pragma once
#include <iostream>
#include <sstream>
#include <map>
#include <exception>

using namespace std;

class Store {
protected:
    map<string, int> storeGoods;

    // Текст при заполнении
    void text(string name);

    // Проверка на целое число
    bool isNum(string &str);

public:
    // Конструктор - заполняет магазин
    Store(string name);

     // Разделяет строку и добавляет в map
     virtual void add(string &str);

     // Удаляет из map по ключу
     virtual void remove(string goodsInfo);

     // Если есть товар, то забирает часть
     virtual void take(map<string, int>::iterator &goods);

     // Показывает все товары и количество
     virtual void showGoods();

     // Деструктор - очищает магазин
    ~Store();
};