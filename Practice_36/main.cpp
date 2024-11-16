#include <QApplication>
#include <QSlider>
#include <QSpinBox>
#include <iostream>
#include <QVBoxLayout>
#include "Circle.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    auto *window = new QWidget;
    auto *circle = new Circle(window);
    auto *slider = new QSlider(Qt::Horizontal, window);
    slider->setMinimum(0);
    slider->setMaximum(100);
    auto *spinbox = new QSpinBox();
    spinbox->setMinimum(0);
    spinbox->setMaximum(100);

    auto layout = new QVBoxLayout(window);
    layout->addWidget(circle);
    layout->addWidget(slider);
    layout->addWidget(spinbox);

    QObject::connect(slider, &QSlider::valueChanged, spinbox, &QSpinBox::setValue);

    QObject::connect(slider, &QSlider::valueChanged,
                     circle, [slider, circle](){
        if (slider->value() <= 33 ) circle->setGreen();
        else if (slider->value() > 33 && slider->value() <= 66) circle->setYellow();
        else circle->setRed();
    });
    QObject::connect( spinbox, QOverload<int>::of(&QSpinBox::valueChanged),
                      slider, &QSlider::setValue);

    QObject::connect(spinbox, QOverload<int>::of(&QSpinBox::valueChanged),
                     circle, [spinbox, circle](){
        if (spinbox->value() >= 33 ) circle->setGreen();
        else if (spinbox->value() > 33 && spinbox->value() <= 66) circle->setYellow();
        else circle->setRed();
    });

    window->setFixedSize(250,300);

    window->show();

    return QApplication::exec();
}
#include "main.moc"