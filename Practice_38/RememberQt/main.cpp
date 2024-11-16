#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <QTimer>

#include <QSpinbox>
#include <QSlider>
//#include <QtNetwork>
//#include <WebEngineView>

#include <QFuture>
#include <QtConcurrent/QtConcurrent>
//
#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
//
#include <QDir>

/*
class Printer : public QObject {
    Q_OBJECT
public slots:
    void printFinished() {
        std::cout << "finished!" << std::endl;
    }
};*/

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    //---------------  Ex_1 -----------------
    //QTimer timer;
    //Printer myPrinter;
    //QObject::connect(&timer, &QTimer::timeout, &myPrinter, &Printer::printFinished);
    //timer.start(2000);

    //--------------- Ex_2 -----------------
    /*auto* button = new QPushButton("Push me, Daddy!");
    auto* slider = new QSlider(Qt::Horizontal);
    auto* spinbox = new QSpinBox();

    spinbox->setMinimum(0);
    spinbox->setMaximum(100);
    slider->setMinimum(0);
    slider->setMaximum(100);

    QObject::connect(slider, &QSlider::valueChanged, spinbox, &QSpinBox::setValue);
    QObject::connect(spinbox, QOverload<int>::of(&QSpinBox::valueChanged), slider, &QSlider::setValue);

    slider->resize(500, 25);
    spinbox->resize(50, 50);
    slider->move(900, 600);
    spinbox->move(800, 500);

    slider->show();
    spinbox->show();*/


    //---------------  Ex_3 -----------------




    return QApplication::exec();
}

#include <main.moc>