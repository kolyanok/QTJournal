#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <mainwindow.h>
#include <TJAPI.h>
#include "HttpRequestWorker.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    //explicit Controller(QObject *parent = 0);
    Controller(MainWindow* mainWindow, QObject *parent = 0);

private:
    MainWindow* mainWindow;
    TJAPI* api;
    ~Controller();

signals:
    void updateText(QString);
    void updateQRString(QString);

public slots:
    //handle ui actions
    void handleUserInfoButton();
    void handleVerifyQRButton(QString);
    void handleGetInfoButton();

    //handle api responses
    void handleGetInfoResult(HttpRequestWorker*);
    void handleGetUserInfoResult(HttpRequestWorker*);
    void handleVerifyQRResult(HttpRequestWorker*);

    //handle library result
    void decodeQR(QStringList);
};

#endif // CONTROLLER_H
