#include "imagebutton.h"

ImageButton::ImageButton(QWidget *parent){
    setParent(parent); // Метод родительского класса для передачи родителя
    setToolTip("Press me"); // Оставляет подсказку при наведении
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed); // Политика размера кнопки - Фиксированная
    //
    mButtonUpPixmap = QPixmap(":/img/ButtonUp.jpg");
    mButtonDownPixmap = QPixmap(":/img/ButtonDown.jpg");
    mCurrentButtonPixmap = mButtonUpPixmap;

    setGeometry(mCurrentButtonPixmap.rect()); // Изменим размеры виджета по размеру картинки
    //mediaPlayer.setMedia(QUrl("qrc:/sound/metallicheskiy-schelchok4.mp3"));
   // mediaPlayer.setMedia(QUrl::fromLocalFile("C:\\Users\\mikha\\Desktop\\SkillBox\\Practice_38\\38_1\\38_1\\metallicheskiy-schelchok4.mp3"));
    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);
    connect(this, &QPushButton::clicked, this, &ImageButton::play);

}

// Рисуем кнопку
void ImageButton::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

// Подсказывает Qt какого размера наш виджет
QSize ImageButton::sizeHint() const {
    return QSize(10, 10);
}

// Минимальный размер виджета
QSize ImageButton::minimumSizeHint() const {
    return sizeHint();
}

// Реагирование на нажатие
void ImageButton::keyPressEvent(QKeyEvent *e){
    setDown();
}

//
void ImageButton::setDown(){
    mCurrentButtonPixmap = mButtonDownPixmap;
    mediaPlayer.stop();
    mediaPlayer.play();
    update();
    QTimer::singleShot(100, this, &ImageButton::setUp);
}

//
void ImageButton::setUp(){
    mCurrentButtonPixmap = mButtonUpPixmap;
    update();
}

//
void ImageButton::play()
{
    mediaPlayer.stop();
    mediaPlayer.setMedia(QUrl("qrc:/sound/metallicheskiy-schelchok4.mp3"));
    mediaPlayer.play();
}
