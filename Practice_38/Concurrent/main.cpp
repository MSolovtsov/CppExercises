#include <QtGui/QtGui>
#include <QApplication>
//
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
//
#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
//
#include <QDir>

#include <iostream>

QImage blureImage(QImage source){   // Закотовка

    if(source.isNull()) return QImage();

    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));
    //
    auto *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(8);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(), QRectF(0, 0, source.width(), source.height()));

    return result;

}

void processSingleImage(QString sourceFile, QString destFile){
    auto blured = blureImage(QImage(sourceFile));
    blured.save(destFile);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // C:/Users/mikha/Desktop/SkillBox/Practice_38/Concurrent/Concurrent
    QDir sourceDir("C:/Users/mikha/Desktop/SkillBox/Practice_38/Concurrent/img");
    QDir destinationDir("C:/Users/mikha/Desktop/SkillBox/Practice_38/Concurrent/res");

    auto images = sourceDir.entryList(QStringList() << "*.jpg" << ".JPG", QDir::Files);
    QElapsedTimer timer;
    timer.start();

    // Многопоточка !
    QList<QFuture<void>> handlers;
    for(auto &filename : images){
        handlers.append(QtConcurrent::run(processSingleImage, sourceDir.path() + "/" + filename,
                                          destinationDir.path() + "/" + "blured_" +filename));
    }

    for(auto &f : handlers)
        f.waitForFinished();

    std::cout << "Clac time: " << timer.elapsed() << " mseconds" << std::endl;

    return a.exec();
}

#include <main.moc>