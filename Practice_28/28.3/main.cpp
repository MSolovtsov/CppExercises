#include <iostream>
#include <vector>
#include <cstdlib>
#include <thread>
#include <ctime>
#include <mutex>

using namespace std;

bool movement = true;
mutex mtxBool;

enum Food{
    Pizza,
    Soup,
    Steak,
    Salad,
    Sushi
};

string strFood(Food i){
    switch (i) {
        case Pizza: return "Pizza";
        case Soup: return "Soup";
        case Steak: return "Steak";
        case Salad: return "Salad";
        case Sushi: return "Sushi";
    }
}

//---------------------------ORDERS--------------------------------------------

vector<Food> orders;

mutex mtx;

void foodGenerator(){
    bool enable_order_flow = true;
    while(enable_order_flow){
        mtxBool.lock();
        enable_order_flow = movement;
        mtxBool.unlock();
        //this_thread::sleep_for(chrono::seconds(5 + rand() % 5));
        Food dish = (Food)(rand() % 5);
        mtx.lock();
        orders.push_back(dish);
        cout << "The order was MADE!\t" << strFood(dish) << endl;
        mtx.unlock();
    }
}

//---------------------------COOKERS--------------------------------------------

vector<Food> cooked;

mutex mtxCookers;

void kitchen(){
    int count = 0;
    bool enable_cook_flow = true;
    while(enable_cook_flow){
        mtxBool.lock();
        enable_cook_flow = movement;
        mtxBool.unlock();

        if (/*!orders.empty() && */count < orders.size()){
            this_thread::sleep_for(chrono::seconds(5 + rand() % 10));
            mtx.lock();
            mtxCookers.lock();

            cooked.push_back(orders[count]);
            cout << "The order was COMPLETED!\t" << strFood(orders[count]) << endl;

            mtxCookers.unlock();
            mtx.unlock();
            count++;
        }
    }
}

//---------------------------MAIN----------------------------------------------

int main() {
    cout << "\nTask #3\n  Simulation of the kitchen of an online restaurant.\n" << endl;

    srand(time(nullptr));

    thread receipt_of_orders(foodGenerator);
    //receipt_of_orders.detach();
    thread cookers(kitchen);
    //cookers.detach();

    int count = 0;
    while(count < 10){
        this_thread::sleep_for(chrono::seconds(30));
        //mtx.lock();
        mtxCookers.lock();
        for (int i = 0; i < cooked.size(); i++){
            count++;
            cout << count << ". " << strFood(cooked[i]) << endl;
            if (count >= 10) break;
        }
        cooked.clear();
        mtxCookers.unlock();
        //mtx.unlock();
    }

    mtxBool.lock();
    movement = false;
    mtxBool.unlock();
    receipt_of_orders.join();
    cookers.join();


    return 0;
}
