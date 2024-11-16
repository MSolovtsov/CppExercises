#include <QApplication>
#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QWebEngineView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto *mainWindow = new QWidget;
    auto *hbox = new QHBoxLayout(mainWindow);
    auto *htmlEdit = new QPlainTextEdit;
    auto webView = new QWebEngineView;

    htmlEdit->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
    webView->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);

    hbox->addWidget(htmlEdit);
    hbox->addWidget(webView);


    QObject::connect(htmlEdit, &QPlainTextEdit::textChanged, [webView, htmlEdit](){
        webView->setHtml(htmlEdit->toPlainText());
    });

    htmlEdit->appendPlainText("<h1>Hello World!</h1>");

    mainWindow->resize(1500, 750);
    mainWindow->show();
    return a.exec();
}
