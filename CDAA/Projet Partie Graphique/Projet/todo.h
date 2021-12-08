/**
    *@file todo.h
    *@brief Fichier en-tête de la classe Todo
    *@author BAH Saikou Oumar
    *@author DIALLO Mamoudou
*/

#ifndef TODO_H_INCLUDED
#define TODO_H_INCLUDED

#include <QDate>
#include <QString>
#include <QDebug>

#include "interaction.h"

/**
    *@class Todo Todo.h "Todo.h"
    *@brief Cette classe permet de créer des taches dans l'application avec une description et une date.
    *@details ...
*/
class Todo
{
    private:
        /// Lien vers l'interaction
        Interaction * lienInteraction;
        /// Le contenu
        QString contenu;
        /// La date
        QDate date;
        /// L'identifiant
        QString id;

    public:
        /// Constructeur par défaut
        Todo();
        /// Constructeur avec paramètres
        Todo(Interaction*, const QString&);
        Todo(Interaction*, const QString&, const QDate&);
        Todo(const Todo&);

        Interaction* getInteraction() const;
        QString getContenu() const;
        QDate   getDate() const;
        QString getStringDate() const;
        QString getID() const;

        void setInteraction(Interaction*);
        void setContenu(const QString&);
        void setDate(const QDate&);
        void setDateFromString(const QString&);
        void setID(const QString&);

        friend QDebug operator<<(QDebug, const Todo&);
        QString toString();
        bool operator==(const Todo&);
        void operator=(const Todo&);

};

#endif // TODO_H_INCLUDED
