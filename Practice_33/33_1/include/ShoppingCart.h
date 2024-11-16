#pragma once
#include "Store.h"

class ShoppingCart : protected Store {

public:
    // Конструктор - заполняет корзину
    ShoppingCart(string name) : Store(std::move(name)){}

    // Начало корзины
    map<string, int>::iterator getCartBegin();

    // Конец корзины
    map<string, int>::iterator getCartEnd();

    // Разделяет строку и добавляет в map
    void add(string &str) override;

    // Удаляет из map по ключу
    void remove(string goodsInfo) override;

    // Если есть товар, то забирает часть
    void take(map<string, int>::iterator &goods) override;

    // Показывает все товары и количество
    void showGoods() override;

    // Деструктор - очищает корзину
    ~ShoppingCart();
};

