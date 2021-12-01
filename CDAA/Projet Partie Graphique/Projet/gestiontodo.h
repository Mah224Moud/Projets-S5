/**
    *@file GestionTodo.h
    *@brief Fichier d'en-tête de la classe GestionTodo
    *@author BAH Saikou Oumar
    *@author DIALLO Mamoudou
*/

#ifndef GESTIONTODO_H
#define GESTIONTODO_H

#include <list>
#include <QDebug>

#include "todo.h"
#include "interaction.h"

/**
    *@class GestionTodo GestionTodo.h "GestionTodo.h"
    *@brief Cette classe permet de gérer une liste de tâches.
    *@details La gestion des tâches se fait indépendamment des intéractions auxquelles elles appartiennent.
*/
class GestionTodo
{
    private:
        /// La liste des tâches
        std::list<Todo> listTodo;

    public:
        /// Constructeur par défaut
        GestionTodo();
        /// Destructeur
        ~GestionTodo();

        /**
            *@brief Accesseur sur la liste de tâches.
            *@details Cette methode renvoie la liste des tâches.
            *@return une liste de tâches.
        */
        const std::list<Todo> getlistTodo() const{ return listTodo;}

        /// Récupération de la taille de la liste.
        inline unsigned getSize(){return listTodo.size();}

        void addTodo(const Todo&);
        void removeTodo(const QString&);
        void removeAllInteractionTodo(const QString&);
        GestionTodo getAllInteractionTodo(const QString&) const;

        friend QDebug operator<<(QDebug, const GestionTodo&);
        QString toString();
};

#endif // GESTIONTODO_H
