#include "Graph.h"

Graph::Graph(string _name, Person* person) : Person(_name) {
    if (person != nullptr) {
        this->base = person;
        reload();
    } else
        this->base = new Person("");
}

void Graph::reGraph(Person* person){
    if (person != nullptr) {
        this->base = person;
        reload();
    } else
        this->base = new Person("");
}

/*bool Graph::isChecked(Person* person){
    for (int k = 0; k < this->checked.size(); k++)
        if (person == this->checked[k])
            return true;
    return false;
}*/

string Graph::check(string _name){

    if (this->queue.front()->getName() == _name) {
        return this->queue.front()->getName();

    } else {
        if (!this->queue.empty()) {
            this->checked.push_back(this->queue.front());
            bool isChecked = false;

            for (int j = 0; j < this->checked.back()->getNumberOfFriends(); j++) {
                for (int k = 0; k < this->checked.size(); k++)
                    if (this->checked.back()->getFriend(j) == this->checked[k]) {
                        isChecked = true;
                        break;
                    }


                if (!isChecked) {
                    this->queue.push_back(this->checked.back()->getFriend(j));
                }
                isChecked = false;
            }
            this->queue.erase(this->queue.begin());
            return check(_name);

        } else
            return "NONE";
    }
}

/*void Graph::find_connections(){
    bool isChecked = false;
    for (int j = 0; j < this->checked.back()->getNumberOfFriends(); j++) {
        for (int k = 0; k < this->checked.size(); k++)
            if (this->checked.back()->getFriend(j) == this->checked[k]) {
                isChecked = true;
                break;
            } else isChecked = false;
        if (!isChecked) {
            this->queue.push_back(this->checked.back()->getFriend(j));
        }
    }
}*/

void Graph::reload(){
    if (!this->queue.empty())
        this->queue.clear();
    if(!this->checked.empty())
        this->checked.clear();
    this->queue.push_back(this->base);
};

string Graph::seek(string _name = ""){
    reload();
    return check(_name);
}

void Graph::showMatrix(){
    seek();

    for (int i = 0; i < this->checked.size(); i++)
        cout << "\t" << this->checked[i]->getName();
    cout << endl;

    bool is = false;

    for (int k = 0; k < this->checked.size(); k++) {
        cout << this->checked[k]->getName();
        for (int i = 0; i < this->checked.size(); i++) {
            for (int j = 0; j < this->checked[i]->getNumberOfFriends(); j++){
                if (this->checked[k] == this->checked[i]->getFriend(j)){
                    is = true;
                    break;
                }

            }
            if (is) {
                cout << "\t1";
                is = false;
            } else cout << "\t0";
        }
        cout << endl;
    }
    reload();

}

void Graph::showAllConections(){
    seek();

    for (int i = 0; i < this->checked.size(); i++){
        cout << this->checked[i]->getName() << ":" << endl;
        this->checked[i]->ShowFriends();
    }
}

Person* Graph::getFront(){
    reload();
    return this->queue.front();
}

Person* Graph::getBack(){
    seek();
    return this->checked.back();;
}