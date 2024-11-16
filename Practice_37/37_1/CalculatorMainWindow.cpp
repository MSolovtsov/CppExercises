#include "CalculatorMainWindow.h"

void CalculatorMainWindow::cleanEdit(){
    if (this->lineEdit->text() == "ERROR")
        this->lineEdit->clear();
}

void CalculatorMainWindow::add0(){
    cleanEdit();
    this->lineEdit->setText(this->lineEdit->text() + "0");
}

void CalculatorMainWindow::add1(){
    cleanEdit();
    this->lineEdit->setText(this->lineEdit->text() + "1");
}

void CalculatorMainWindow::add2(){
    cleanEdit();
    this->lineEdit->setText(this->lineEdit->text() + "2");
}

void CalculatorMainWindow::add3(){
    cleanEdit();
    this->lineEdit->setText(this->lineEdit->text() + "3");
}

void CalculatorMainWindow::add4(){
    cleanEdit();
    this->lineEdit->setText(this->lineEdit->text() + "4");
}

void CalculatorMainWindow::add5(){
    cleanEdit();
    this->lineEdit->setText(this->lineEdit->text() + "5");
}

void CalculatorMainWindow::add6(){
    cleanEdit();
    this->lineEdit->setText(this->lineEdit->text() + "6");
}

void CalculatorMainWindow::add7(){
    cleanEdit();
    this->lineEdit->setText(this->lineEdit->text() + "7");
}

void CalculatorMainWindow::add8(){
    cleanEdit();
    this->lineEdit->setText(this->lineEdit->text() + "8");
}

void CalculatorMainWindow::add9(){
    cleanEdit();
    this->lineEdit->setText(this->lineEdit->text() + "9");
}

void CalculatorMainWindow::addDot(){
    cleanEdit();
    if (this->lineEdit->text().isEmpty())
        add0();
    this->lineEdit->setText(this->lineEdit->text() + ".");
}

void CalculatorMainWindow::clear(){
    this->lineEdit->clear();
    this->command = Command::None;
}

void CalculatorMainWindow::save(float& digit){
    digit = this->lineEdit->text().toFloat();
    this->lineEdit->clear();
}

void CalculatorMainWindow::plus(){
    save(this->buf);
    this->command = Command::Plus;
}

void CalculatorMainWindow::minus(){
    save(this->buf);
    this->command = Command::Minus;
}

void CalculatorMainWindow::multiply(){
    save(this->buf);
    this->command = Command::Multiply;
}

void CalculatorMainWindow::divide(){
    save(this->buf);
    this->command = Command::Divide;
}

QString CalculatorMainWindow::res() {
    switch (this->command) {
        case Command::Plus:
            return QString::number(this->buf + this->num);

        case Command::Minus:
            return QString::number(this->buf - this->num);

        case Command::Multiply:
            return QString::number(this->buf * this->num);

        case Command::Divide:
            if (this->num == 0)
                return "ERROR";
            else
                return QString::number(this->buf / this->num);

        case Command::None:
            return "ERROR";
    }
}

void CalculatorMainWindow::equals(){
    save(this->num);
    this->lineEdit->setText(res());
    this->command = Command::None;
}
