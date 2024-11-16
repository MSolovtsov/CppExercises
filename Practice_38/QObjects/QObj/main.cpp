#include <QApplication>
#include <QObject>
#include <iostream>

class MyClass : public QObject{
    Q_OBJECT
    int mAge;
public:
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged FINAL);
    void setAge(int nAge){mAge = nAge;}
    int age(){return mAge;}

signals:
    void ageChanged(int);
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyClass hero;
    hero.setProperty("height", 180);

    std::cout << "Height: " << hero.property("height").toUInt() << std::endl;
    return a.exec();
}

#include <main.moc>
