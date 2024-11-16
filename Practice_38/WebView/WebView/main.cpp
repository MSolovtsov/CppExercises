#include "mainwindow.h"

#include <QApplication>
#include <QWebEngineView>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QPushButton>



BrowserTabWidget* createNewBrowserWindow(){

    auto *browserWindow = new BrowserTabWidget;
    auto *urlLineEdit = new QLineEdit;
    auto *vbox = new QVBoxLayout(browserWindow);
    auto *webView = new QWebEngineView;

    //webView->setUrl(QUrl("http://skillbox.ru"));  // отображение сайта в окне
    //webView->setHtml("<H1>Hello World!</H1>");     // html страничка

    vbox->addWidget(urlLineEdit);
    vbox->addWidget(webView);
    //
    QObject::connect(urlLineEdit, &QLineEdit::returnPressed, [webView, urlLineEdit](){
        auto urlToOpen = urlLineEdit->text();
        webView->load(urlToOpen);
    });

    QObject::connect(webView, &QWebEngineView::loadFinished, [webView, browserWindow](bool ok){
        if (ok)
            emit browserWindow->tabLoadingFinished(webView->title());
    });

    return browserWindow;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTabWidget tabs;

    QPushButton newTabButton("+");
    tabs.setTabsClosable(true);     // Крестик на табах
    tabs.setCornerWidget(&newTabButton, Qt::BottomLeftCorner);   // Устанавление кнопки в левый нижний угол виджета с вкладками
    //
    QObject::connect(&newTabButton, &QPushButton::clicked, [&tabs](){
        auto newTab = createNewBrowserWindow();
        // Отображает название вкладки
        QObject::connect(newTab, &BrowserTabWidget::tabLoadingFinished, [&tabs](QString newTitle){
            tabs.setTabText(tabs.currentIndex(), newTitle);     // Для i вкладки установить название
            tabs.setWindowTitle(newTitle);      // Устанавливаем название для всего окна
        });
        tabs.addTab(newTab, "tab " + QString::number(tabs.count() + 1)); // Пока страница не загрузилась назначем название
    });


    //tabs.addTab(createNewBrowserWindow(), "tab1");
    //tabs.addTab(createNewBrowserWindow(), "tab2");

    newTabButton.click();
    //

    // Удаление вкладок
    QObject::connect(&tabs, &QTabWidget::tabCloseRequested, [&tabs](int indexToRemove){
        if (tabs.count() > 1) {
            auto widgetToDelete = tabs.widget(indexToRemove);
            delete widgetToDelete;
        }
    });

    // Меняет название окна на название открытого таба
    QObject::connect(&tabs, &QTabWidget::currentChanged, [&tabs](int currentIndex){
        tabs.setWindowTitle(tabs.tabText(currentIndex));
    });

    tabs.show();
    return a.exec();
}
