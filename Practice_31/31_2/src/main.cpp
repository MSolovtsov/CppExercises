#include <iostream>
#include "Graph.h"

using namespace std;

void showPerson_Name_Friends(Person* person){
    cout << "\tname: " << person->getName() << endl;
    person->ShowFriends();
}

int main() {
    cout << "\nTask 2\n  Implementation of the graph class\n" << endl;

    Person* user = new Person("YOU");
    user->fillSocialCircle(2);
    showPerson_Name_Friends(user);
    cout << "==========" << endl;

    Person* f = new Person("Vanya");
    user->fillSocialCircle(f);
    showPerson_Name_Friends(user);
    cout << "===========" << endl;

    Graph* graph = new Graph(f->getName(), f);
    showPerson_Name_Friends(graph->getFront());
    cout << "===========" << endl;
    f->fillSocialCircle(1);
    showPerson_Name_Friends(graph->getFront());
    cout << "===========" << endl;

    //cout << graph->seek("3") << endl;
    //cout << graph->seek("YOU") << endl;

    graph->showMatrix();


    cout << "\n\n=======================\n=======================\n" << endl;


    user->getFriend(1)->fillSocialCircle(f->getFriend(1));
    showPerson_Name_Friends(user->getFriend(1));
    cout << endl;
    showPerson_Name_Friends(f->getFriend(1));

    user->getFriend(0)->fillSocialCircle(2);
    showPerson_Name_Friends(user->getFriend(0));
    graph->reGraph(user->getFriend(0));

    graph->showMatrix();
    cout << endl;
    //graph->showAllConections();

    f->fillSocialCircle(1);
    graph->showMatrix();

    return 0;
}
