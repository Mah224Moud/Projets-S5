#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    button = new QPushButton(this);
    button -> setText("Bouton");

    QObject::connect(&datas, SIGNAL(errorDataBase(const QString&)), this, SLOT(errorHappened(const QString&)));
    QObject::connect(&datas, SIGNAL(infoDataBase(const QString&)), this, SLOT(infoReceived(const QString&)));
    QObject::connect(button, SIGNAL(clicked()), this, SLOT(refresh()));
    QObject::connect(this, SIGNAL(refreshContacts(GestionContact&)), &datas, SLOT(refreshing(GestionContact&)));
    QObject::connect(&datas, SIGNAL(refreshed()), this, SLOT(showContact()));



}

MainWindow::~MainWindow()
{

}

void MainWindow::errorHappened(const QString& msg)
{
    QMessageBox::critical(0,"ERREUR", msg, QMessageBox::Ok);
}

void MainWindow::warningHappened(const QString& msg)
{
    QMessageBox::warning(0,"ATTENTION", msg, QMessageBox::Ok);
}

void MainWindow::infoReceived(const QString& msg)
{
    QMessageBox::information(0,"INFO", msg, QMessageBox::Ok);
}

void MainWindow::showContact()
{
    qDebug() << gestC;  
}

void MainWindow::refresh()
{
    emit refreshContacts(gestC);
}
