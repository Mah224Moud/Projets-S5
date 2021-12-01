#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>

#include "email.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void errorHappened(const QString&);
};
#endif // MAINWINDOW_H
