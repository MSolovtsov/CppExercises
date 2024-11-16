#pragma once
#include <QMainWindow>
#include <QtWidgets/QLineEdit>


class CalculatorMainWindow : public QMainWindow {
    Q_OBJECT
private:
    enum Command{
        None = 0,
        Plus = 1,
        Minus = 2,
        Multiply = 4,
        Divide = 8
    };

    Command command = Command::None;

    float buf = 0.f;
    float num = 0.f;

    void save(float& digit);
    void cleanEdit();
    QString res();

public:
    QLineEdit* lineEdit = nullptr;

    CalculatorMainWindow(QWidget* parent = nullptr) : QMainWindow(parent) {};

public slots:
    void add0();
    void add1();
    void add2();
    void add3();
    void add4();
    void add5();
    void add6();
    void add7();
    void add8();
    void add9();
    void addDot();
    void clear();
    void plus();
    void minus();
    void multiply();
    void divide();
    void equals();

};
