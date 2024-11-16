#include "Store.h"

// Проверка на целое число
bool Store::isNum(string &str){
    for (int i = 0; i < str.size() - 1; i++){
        if (str[i] < 48 || str[i] > 57) {
            throw invalid_argument("\"" + str + "\" is not number");       // todo Ошибка!
        }
    }
    return true;
}

// Конструктор - заполняет магазин
Store::Store(string name){
    text(name);
    string goodsData = "";

    while (goodsData != "end") {
        getline(cin, goodsData);

        if (goodsData != "end"){
            add(goodsData);
        }
    }
}

// Текст при заполнении
void Store::text(string name){
    cout << "Fill goods in the " << name << ":" << endl;
    cout << "\t< Name quantity >" << endl;
    cout << "Enter \"end\" to exit\n" << endl;
    cout << "Enter: " << endl;
}

// Разделяет строку и добавляет в map
void Store::add(string &str){
    string goodsName;
    string goodsQuantity;
    stringstream temp_stream(str);
    temp_stream >> goodsName >> goodsQuantity;


    try {
        if (isNum(goodsQuantity))
            this->storeGoods.insert( pair<string, int>(goodsName, stoi(goodsQuantity)));
    } catch (const invalid_argument& e) {
        cerr << "Logical error: " << e.what() << endl;
    }

}

// Удаляет из map по ключу
void Store::remove(string goodsInfo){
    this->storeGoods.erase(goodsInfo);
}

// Если есть товар, то забирает часть
void Store::take(map<string, int>::iterator &goods){

    for (auto it = this->storeGoods.begin();
                it != this->storeGoods.end(); it++){
        if (it->first == goods->first) {

            if (it->second >= goods->second){
                it->second -= goods->second;

            } else {
                throw runtime_error("too many " + goods->first);            // todo Ошибка!
            }
        }
    }
}

// Показывает все товары и количество
void Store::showGoods(){
    if (!this->storeGoods.empty()) {
        for (map<string, int>::iterator it = this->storeGoods.begin();
                it != this->storeGoods.end(); it++) {
            cout << "\t" << it->first << "\t--  " << it->second << endl;
        }
        cout << endl;
    } else
        cout << "\t Is empty!" << endl;
}

// Деструктор - очищает магазин
Store::~Store(){
    this->storeGoods.clear();
}