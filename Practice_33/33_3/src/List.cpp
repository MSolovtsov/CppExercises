#include "List.h"

// Выносит элемент num'ого положения в конец вектора и удаляет
template<typename T_key, typename T_value>
void List<T_key, T_value>::deleteLine(int num){
    for (int i = num; i < this->mainList.size() - 1; i++){
        Registry buf = this->mainList[i];
        this->mainList[i] =  this->mainList[i + 1];
        this->mainList[i + 1] = buf;
    }
    this->mainList.pop_back();
}

// Выводит сообщение, что лист - пустой
template<typename T_key, typename T_value>
void List<T_key, T_value>::listIsEmpty(){
    if (this->mainList.empty()) throw runtime_error("List is empty");
}

// Добавляет элемент с ключом
template<typename T_key, typename T_value>
void List<T_key, T_value>::add(T_key _key, T_value _value){
    this->mainList.push_back({_key, _value});
}

// Удаляет элемент по ключу
template<typename T_key, typename T_value>
void List<T_key, T_value>::remove(T_key _key){

    try {
        listIsEmpty();

        for (int i = 0; i < this->mainList.size(); i++) {
            if (this->mainList[i].key == _key) {
                deleteLine(i);
                continue;
            }
        }

    } catch(runtime_error& e) {
        cerr << "List::remove() "
                "\n\tLogic error: " << e.what() << endl;
    }

}

// Отображает все значения с ключами
template<typename T_key, typename T_value>
void List<T_key, T_value>::print(){

    try {
        listIsEmpty();

        for (int i = 0; i < this->mainList.size(); i++){
            cout << "\t" << this->mainList[i].key << "  " << this->mainList[i].value << endl;
        }
        cout << endl;

    } catch(runtime_error& e) {
        cerr << "List::print()"
                "\n\tLogic error: " << e.what() << endl;
    }

}

// Находит значение элемента по ключу
template<typename T_key, typename T_value>
T_value List<T_key, T_value>::find(T_key _key){

    try {
        listIsEmpty();

        for (int i = 0; i < this->mainList.size(); i++) {
            if (this->mainList[i].key == _key) {
                return this->mainList[i].value;
            }
        }
        return nullptr;

    } catch(runtime_error& e) {
        cerr << "List::find()"
                "\n\tLogic error: " << e.what() << endl;
    }

}

// Деструктор - очищает вектор
template<typename T_key, typename T_value>
List<T_key, T_value>::~List(){
    if(!this->mainList.empty())
        this->mainList.clear();
}
