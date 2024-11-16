#include <QApplication>
//
#include <QMediaPlayer>
#include <QMediaContent>
//
#include <QVideoWidget>
//
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Gui
    QWidget playerWindow;
    QVBoxLayout vbox(&playerWindow);
    QHBoxLayout buttons;
    // Video
    auto *videoWidget = new QVideoWidget;
    vbox.addWidget(videoWidget);
    QSlider *songSlider = new QSlider(&playerWindow);
    songSlider->setOrientation(Qt::Horizontal);
    vbox.addWidget(songSlider);

    auto *openFileButton = new QPushButton("Open", &playerWindow);
    auto *playMediaButton = new QPushButton("Play", &playerWindow);
    auto *pauseMediaButton = new QPushButton("Pause", &playerWindow);

    buttons.addWidget(openFileButton);
    buttons.addWidget(playMediaButton);
    buttons.addWidget(pauseMediaButton);

    vbox.addLayout(&buttons);

    //
    QString filePath;

    auto *player = new QMediaPlayer(&playerWindow);
    //player->setVideoOutput(videoWidget); // Сообщаем plaer куда выводим видео-поток

    bool isPlaying = false;

    QObject::connect(openFileButton, &QPushButton::clicked, [&filePath, player, &isPlaying]{
        filePath = QFileDialog::getOpenFileName(nullptr, // Желаем получить обычный файловый диалог без родителя
                                                "Open Media", // Название зоголовка окна
                                                "", // Путь, с которого мы начинаем искать
                                                "Media files (*.mp3)"); // Тип файла
        player->stop();
        isPlaying = false;
    });

    // Обработка нажатия клавиши Play
    QObject::connect(playMediaButton, &QPushButton::clicked, [&isPlaying, songSlider, player, &filePath]{
        if(!isPlaying){
            player->setMedia(QUrl::fromLocalFile(filePath));
            player->setVolume(75);
            // Установка максимального и минимального значений слайдера
            QObject::connect(player, &QMediaPlayer::durationChanged, [songSlider](qint64 duration){
                songSlider->setMinimum(0);
                songSlider->setMaximum(duration);
            });

            // Устанвка оптимального значения для слайдера
            QObject::connect(player, &QMediaPlayer::positionChanged, [songSlider](qint64 pos){
                songSlider->setValue(pos);
            });

            isPlaying =true;
        }
        player->play();
    });

    // Перемотка слайдера
    QObject::connect(songSlider, &QSlider::valueChanged, player, &QMediaPlayer::setPosition);
    // Обработка кнопки Pause
    QObject::connect(pauseMediaButton, &QPushButton::clicked, player, &QMediaPlayer::pause);


    playerWindow.show();
    return a.exec();
}
