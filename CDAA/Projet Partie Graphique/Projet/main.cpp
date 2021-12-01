#include "mainwindow.h"

#include <QApplication>
#include <QDate>
#include <QTime>
#include <QDebug>

#include "interaction.h"
#include "todo.h"
#include "gestiontodo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Contact c("BAH", "Saikou Oumar", "Oumar's");

    qDebug() << c;

    Interaction i;
    i.setContenu("Test Contenu intéraction");
    i.setDateFromString("14/07/2021");
    i.setContact(&c);

    //qDebug() << i;

    Interaction i1;
    i1.setContenu("Test Contenu intéraction 2");
    i1.setContact(&c);
    i1.setID("yyyy");

    Todo td(&i, "Test Todo 1", QDate::currentDate());
    td.setDateFromString("10/12/2021");

    Todo td1(&i, "Test Todo 2", QDate::fromString("12102022", "ddMMyyyy"));

    Todo td2(&i1, "Test Todo 3");

    GestionTodo gtd;
    gtd.addTodo(td);
    gtd.addTodo(td1);
    gtd.addTodo(td2);

    gtd.removeAllInteractionTodo(i.getID());
    //qDebug() << gtd.removeTodo(td.getID()).toString();
    qDebug() << gtd;

    w.show();
    return a.exec();
}
