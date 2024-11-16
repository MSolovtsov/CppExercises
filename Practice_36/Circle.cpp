#include "Circle.h"

Circle::Circle(QWidget *parent) {

    // Метод родительского класса (перенесем родителя)
    setParent(parent);
    // Подсказка во всплывающем виджете при наведении на кнопку
    setToolTip("Circle!");
    // Определяем то, как нужно работать с размерами данного виджета
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    // Пути к картинкам
    mCircleGreenPixmap = QPixmap(
            R"(C:\Users\mikha\Desktop\SkillBox\Practice_36\GreenCircle.png)"
    );
    mCircleYellowPixmap = QPixmap(
            R"(C:\Users\mikha\Desktop\SkillBox\Practice_36\YellowCircle.png)"
    );
    mCircleRedPixmap = QPixmap(
            R"(C:\Users\mikha\Desktop\SkillBox\Practice_36\RedCircle.png)"
    );
    mCurrentCirclePixmap = mCircleGreenPixmap;
    // Изменим размеры виджета
    setGeometry(mCurrentCirclePixmap.rect() /* Размер картинки */);
    // Обработчик событий
    // connect();
}

// Отображает наш виджет
void Circle::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentCirclePixmap);
}

// Подсказывает Qt, какого размера будет наш виджет
QSize Circle::sizeHint() const {
    return QSize(250, 250);
}

QSize Circle::minimumSizeHint() const {
    return sizeHint();
}

void Circle::setGreen(){
    mCurrentCirclePixmap = mCircleGreenPixmap;
    update(); // !!!!!!!!!!!
}

void Circle::setYellow(){
    mCurrentCirclePixmap = mCircleYellowPixmap;
    update(); // !!!!!!!!!!!
}

void Circle::setRed(){
    mCurrentCirclePixmap = mCircleRedPixmap;
    update(); // !!!!!!!!!!!
}