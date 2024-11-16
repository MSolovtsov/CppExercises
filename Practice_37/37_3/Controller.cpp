#include "Controller.h"

void Controller::checking_for_zero() const{

    if (this->channels->text() == "0")
        this->channels->clear();

}

void Controller::checking_for_console(){
    if (!this->isConsole)
        this->channels->clear();

    this->isConsole = true;
}

void Controller::add0(){
    checking_for_zero();
    checking_for_console();
    if (this->channels->text().size() < 3)
        this->channels->setText(this->channels->text() + "0");
}

void Controller::add1(){
    checking_for_console();
    checking_for_zero();
    if (this->channels->text().size() < 3)
        this->channels->setText(this->channels->text() + "1");
}

void Controller::add2(){
    checking_for_console();
    checking_for_zero();
    if (this->channels->text().size() < 3)
        this->channels->setText(this->channels->text() + "2");
}

void Controller::add3(){
    checking_for_console();
    checking_for_zero();
    if (this->channels->text().size() < 3)
        this->channels->setText(this->channels->text() + "3");
}

void Controller::add4(){
    checking_for_console();
    checking_for_zero();
    if (this->channels->text().size() < 3)
        this->channels->setText(this->channels->text() + "4");
}

void Controller::add5(){
    checking_for_console();
    checking_for_zero();
    if (this->channels->text().size() < 3)
        this->channels->setText(this->channels->text() + "5");
}

void Controller::add6(){
    checking_for_console();
    checking_for_zero();
    if (this->channels->text().size() < 3)
        this->channels->setText(this->channels->text() + "6");
}

void Controller::add7(){
    checking_for_console();
    checking_for_zero();
    if (this->channels->text().size() < 3)
        this->channels->setText(this->channels->text() + "7");
}

void Controller::add8(){
    checking_for_console();
    checking_for_zero();
    if (this->channels->text().size() < 3)
        this->channels->setText(this->channels->text() + "8");
}

void Controller::add9(){
    checking_for_console();
    checking_for_zero();
    if (this->channels->text().size() < 3)
        this->channels->setText(this->channels->text() + "9");
}

void Controller::valueUp(){
    int value = this->value->text().toInt();
    if (value < 100){
        value += 10;
        this->value->text().clear();
        this->value->setText(QString::number(value));
    }

}

void Controller::valueDown(){
    int value = this->value->text().toInt();
    if (value > 0 ){
        value -= 10;
        this->value->text().clear();
        this->value->setText(QString::number(value));
    }
}

void Controller::channelUp(){
    this->isConsole = false;
    int channels = this->channels->text().toInt();
    if (channels < 999)
        channels++;
    else
        channels = 0;

    this->channels->text().clear();
    this->channels->setText(QString::number(channels));
}

void Controller::channelDown(){
    this->isConsole = false;
    int channels = this->channels->text().toInt();

    if (channels > 0)
        channels--;
    else
        channels = 999;

    this->channels->text().clear();
    this->channels->setText(QString::number(channels));
}
