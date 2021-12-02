#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

}

MainWindow::~MainWindow()
{

}

void MainWindow::errorHappened(const QString& msg)
{
    QMessageBox msgError;
    msgError.critical(0,"ERREUR", msg, QMessageBox::Ok);
}
