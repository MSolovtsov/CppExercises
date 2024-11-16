#include <QApplication>
#include <QMediaPlayer>
#include <QMediaContent>
#include <iostream>
#include "imagebutton.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageButton myButton(nullptr); // nullptr - потому что кнопка явл. главным окном приложения
    myButton.setFixedSize(500, 500); // размер кнопки
    myButton.move(1000, 400); // переместим кнопку по экрану

    // Костыль
    //QMediaPlayer player;
    //player.setMedia(QUrl::fromLocalFile("C:/Users/mikha/Desktop/SkillBox/Practice_38/38_1/38_1/sound/metallicheskiy-schelchok4.mp3"));


    QObject::connect(&myButton, &QPushButton::clicked, [/*&player*/](){
        //player.play();
        cout << "click!" << endl;
    });

    myButton.show();
    return a.exec();
}

#include <main.moc>
