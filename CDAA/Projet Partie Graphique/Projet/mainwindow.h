#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QString>

#include "email.h"
#include "gestioncontact.h"
#include "database.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPushButton* button;
    GestionContact gestC;
    DataBase datas;

public slots:
    void errorHappened(const QString&);
    void warningHappened(const QString&);
    void infoReceived(const QString&);
    void refresh();
    void showContact();

signals:
    void refreshContacts(GestionContact&);

};
#endif // MAINWINDOW_H
