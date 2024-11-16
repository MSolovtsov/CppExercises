#include <QApplication>
#include "ui_calculator.h"
#include "CalculatorMainWindow.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    CalculatorMainWindow window(nullptr);
    Ui::MainWindow calculator;
    calculator.setupUi(&window);
    window.lineEdit = calculator.lineEdit;

    window.resize(500, 640);
    window.show();
    return QApplication::exec();
}
