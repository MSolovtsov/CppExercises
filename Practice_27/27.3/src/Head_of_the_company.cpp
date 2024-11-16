#include "Head_of_the_company.h"

Head_of_the_company::Head_of_the_company() {
    cout << "Enter number of teames: ";
    cin >> this->numberOfManagers;

    cout << "Enter company direction: ";
    cin >> this->company_direction;
/*}

void Head_of_the_company::distribution(){*/
    this->teams = new Manager[this->numberOfManagers];
    for (int i{0}; i < this->numberOfManagers; i++){
        (this->teams + i)->callManager(i);
        (this->teams + i)->fillWorkers(i, this->company_direction);
    }

    for (int i = 0; i < this->numberOfManagers; i++){
        cout << "(" << i + 1 << ")  ";
        (this->teams + i)->printTeam();
    }

}
