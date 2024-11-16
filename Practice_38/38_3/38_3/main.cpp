#include <QApplication>
#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
//
#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QPainter>
//
#include <QFileDialog>


QImage blurImage(QImage source, int blurRadius){   // Закотовка

    if(source.isNull()) return QImage();

    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));
    //
    auto *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurRadius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(), QRectF(0, 0, source.width(), source.height()));

    return result;

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto *mainWindow = new QWidget;
    auto *vbox = new QVBoxLayout(mainWindow);
    auto *img = new QLabel;
    auto *blurSlider = new QSlider;
    blurSlider->setMinimum(0);
    blurSlider->setMaximum(10);
    auto *workSpace = new QHBoxLayout;

    /*vbox->addWidget(img);
    blurSlider->setOrientation(Qt::Horizontal);
    vbox->addWidget(blurSlider); // */

    blurSlider->setOrientation(Qt::Vertical);
    workSpace->addWidget(blurSlider);
    workSpace->addWidget(img);
    vbox->addLayout(workSpace);

    auto *openFileButton = new QPushButton("Open", mainWindow);

    vbox->addWidget(openFileButton);

    //
    QString filePath;
    // Обработка нажатия клавиши Open
    QObject::connect(openFileButton, &QPushButton::clicked, [&filePath, img]{
        filePath = QFileDialog::getOpenFileName(nullptr, // Желаем получить обычный файловый диалог без родителя
                                                "Open Image", // Название зоголовка окна
                                                "", // Путь, с которого мы начинаем искать
                                                "Image files (*.jpg)"); // Тип файла
        img->setPixmap(QPixmap::fromImage(QImage(filePath).scaled(
            img->width(),
            img->height(),
            Qt::KeepAspectRatio
        )));
    });

    QObject::connect(blurSlider, &QSlider::valueChanged, [&filePath, img, blurSlider]{
        img->setPixmap(QPixmap::fromImage(blurImage(QImage(filePath),blurSlider->value()).scaled(
            img->width(),
            img->height(),
            Qt::KeepAspectRatio
        )));
    });

    mainWindow->resize(600, 500);
    mainWindow->show();
    return a.exec();
}
