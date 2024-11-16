#include <iostream>
#include <map>
#include "Store.h"
#include "ShoppingCart.h"

using namespace std;

int main() {
    cout << "\nTask #1\n\tShopping cart\n" << endl;

    // Создаем магазин
    Store* store = new Store("Store");
    // Показываем все товары
    store->showGoods();

    // Создаем корзину // Наполняем корзину
    ShoppingCart* cart = new ShoppingCart("Shopping Cart");


    for (auto it = cart->getCartBegin();
                it != cart->getCartEnd(); it++) {
        try {
            store->take(it);
        } catch (runtime_error &e) {
            cerr << "Logical error: " << e.what() << endl;
        }

    }

    store->showGoods();

    delete cart;
    delete store;
    return 0;
}
