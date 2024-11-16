#pragma once
#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <iostream>

class Circle : public QWidget {
Q_OBJECT
public:
    Circle() = default;
    Circle(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

public slots:
    void setGreen();
    void setYellow();
    void setRed();

private:
    QPixmap mCurrentCirclePixmap; // Картинка текущенго момента круга
    QPixmap mCircleGreenPixmap; // Картинка зеленого круга
    QPixmap mCircleYellowPixmap; // Картинка желтого круга
    QPixmap mCircleRedPixmap;   // Картинка красного круга

};
