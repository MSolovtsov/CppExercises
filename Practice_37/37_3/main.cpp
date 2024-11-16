#include <QApplication>
#include "ui_controller.h"
#include "Controller.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Controller window(nullptr);
    Ui::MainWindow controller;
    controller.setupUi(&window);
    window.channels = controller.edt_channel;
    window.value = controller.edt_value;

    window.resize(240, 680);
    window.show();
    return QApplication::exec();
}
