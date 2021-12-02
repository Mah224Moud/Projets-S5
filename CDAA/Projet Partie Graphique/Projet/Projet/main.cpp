#include "mainwindow.h"

#include <QApplication>
#include <QDate>
#include <QTime>
#include <QDebug>

#include "interaction.h"
#include "todo.h"
#include "gestiontodo.h"
#include "gestioninteraction.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Contact c("BAH", "Saikou Oumar", "Oumar's");
    c.setID("ct0");
    //qDebug() << c;
    Contact c1("BARRY", "OSAMU", "WORLD");
    c1.setID("ct1");
    //qDebug() << c1;

    Interaction i(&c);
    i.setContenu("Test Contenu intéraction");
    i.setDateFromString("14/07/2021");
    i.setContact(&c);
    i.setID("it01");
    Interaction i1(&c);
    i1.setContenu("Test Contenu intéraction 2");
    i1.setContact(&c);
    i1.setID("it02");
    Interaction i2(&c1, "Test Contenu intéraction 3");
    i2.setDateFromString("16/12/1978");
    i2.setID("it03");
    Interaction i3(&c1, "Test Contenu intéraction 4");
    i3.setID("it04");
    i3.setContact(&c1);

    GestionInteraction gesti;
    gesti.addInteraction(i);
    gesti.addInteraction(i1);
    gesti.addInteraction(i2);
    gesti.addInteraction(i3);

    //gesti.removeInteraction("it01");

    //qDebug() << gesti.getAllContactInteraction(c1.getID());

    //gesti.removeAllContactInteraction(c1.getID());
    qDebug() << gesti;

    Todo td(&i, "Test Todo 1", QDate::currentDate());
    td.setDateFromString("10/12/2021");
    Todo td1(&i, "Test Todo 2", QDate::fromString("12102022", "ddMMyyyy"));
    Todo td2;
    td2.setContenu("Test Todo 3");
    td2.setInteraction(&i1);
    Todo td3(&i2, "Test Todo 4");
    Todo td4(&i2, "Test Todo 5");
    Todo td5(&i3, "Test Todo 6", QDate::fromString("01112001", "ddMMyyyy"));

    GestionTodo gtd;
    gtd.addTodo(td);
    gtd.addTodo(td1);
    gtd.addTodo(td2);
    gtd.addTodo(td3);
    gtd.addTodo(td4);
    gtd.addTodo(td5);

    qDebug() << gtd;

    w.show();
    return a.exec();
}
