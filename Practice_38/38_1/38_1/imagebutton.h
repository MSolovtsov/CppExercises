#pragma once
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaContent>

#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H


class ImageButton : public QPushButton{
    Q_OBJECT
public:
    // Конструкторы
    ImageButton() = default;
    ImageButton(QWidget *parent);
    // Переопределенные функции
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;

public slots:
    void setUp();
    void setDown();
    void play();
private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
    QMediaPlayer mediaPlayer;
};

#endif // IMAGEBUTTON_H
