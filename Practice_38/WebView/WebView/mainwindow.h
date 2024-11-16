#pragma once
#include <QWidget>

class BrowserTabWidget : public QWidget {
    Q_OBJECT

signals:
    void tabLoadingFinished(QString tabTitle);

};
