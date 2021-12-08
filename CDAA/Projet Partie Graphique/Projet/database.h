/**
    *@file database.h
    *@brief Fichier d'entête de la classe Email
    *@author DIALLO Mamoudou
    *@author BAH Saikou Oumar
*/

#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include "contact.h"
#include "gestioncontact.h"
#include "gestioninteraction.h"
#include "gestiontodo.h"

/**
 * @brief The DataBase class permet de comminuquer avec la base de données
 *
 */

class DataBase: public QObject
{
    Q_OBJECT
private:
    QSqlDatabase database;
    bool open;
public:
    DataBase();
    ~DataBase();

    void connexion();
    void close();
    bool isOpen(){return open;}

    bool addContact(const Contact&);
    Contact getContact(const QString&, const QString&, const QString&);
    bool removeConctact(const QString&);
    bool updateContact(const Contact&, const Contact&);

    bool addInteraction(const Interaction&);
    bool removeInteraction(const QString&);
    bool updateInteraction(const Interaction&, const Interaction&);

    bool addTodo(const Todo&);
    bool removeTodo(const QString&);
    bool updateTodo(const Todo&, const Todo&);

signals:
    void errorDataBase(const QString&);
    void infoDataBase(const QString&);
    void refreshed();

public slots:
    void refreshingContacts(GestionContact&);
    void refreshingInteractions(GestionContact&);
    void refreshingTodos(GestionContact&);
    void refreshing(GestionContact&);
};

#endif // DATABASE_H
