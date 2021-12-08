#include "mainwindow.h"

#include <QApplication>
#include <QDate>
#include <QTime>
#include <QDebug>

#include "interaction.h"
#include "todo.h"
#include "gestiontodo.h"
#include "gestioninteraction.h"
#include "gestioncontact.h"
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
