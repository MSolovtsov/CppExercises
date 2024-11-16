#include "ShoppingCart.h"

// Начало корзины
map<string, int>::iterator ShoppingCart::getCartBegin(){
    return this->storeGoods.begin();
}

// Конец корзины
map<string, int>::iterator ShoppingCart::getCartEnd(){
    return this->storeGoods.end();
}

// Разделяет строку и добавляет в map
void ShoppingCart::add(string &str) {
    Store::add(str);
}

// Удаляет из map по ключу
void ShoppingCart::remove(string goodsInfo) {
    Store::remove(goodsInfo);
}

// Если есть товар, то забирает часть
void ShoppingCart::take(map<string, int>::iterator &goods) {
    Store::take(goods);
}

// Показывает все товары и количество
void ShoppingCart::showGoods() {
    Store::showGoods();
}

// Деструктор - очищает корзину
ShoppingCart::~ShoppingCart(){
    this->storeGoods.clear();
}