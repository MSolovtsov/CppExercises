#pragma once
#include <QMainWindow>
#include <QtWidgets/QLineEdit>

class Controller : public QMainWindow {
    Q_OBJECT

private:
    bool isConsole = true;
    void checking_for_zero() const;
    void checking_for_console();

public:
    QLineEdit* channels = nullptr;
    QLineEdit* value = nullptr;
    Controller(QWidget* parent = nullptr) : QMainWindow(parent){};


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
    void valueUp();
    void valueDown();
    void channelUp();
    void channelDown();

};
