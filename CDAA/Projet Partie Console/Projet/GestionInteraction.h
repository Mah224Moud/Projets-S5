/**
    *@file GestionInteraction.h
    *@brief Fichier d'en-tete de la classe GestionInteraction
    *@author BAH Saikou Oumar
    *@author DIALLO Mamoudou
*/

#ifndef GESTIONINTERACTION_H
#define GESTIONINTERACTION_H

#include <list>
#include <iostream>
#include <ostream>

#include "Interaction.h"
#include "GestionTodo.h"

/**
    *@class GestionInteraction GestionInteraction.h "GestionInteraction.h"
    *@brief Cette classe permet de gérer une liste d'interaction ainsi que les taches (todo) liées à chaque intéraction.
    *@details Elle permet notamment l'ajout d'une interaction, d'un todo, leur suppression et l'affichage de toutes les intéractions d'un contact
*/
class GestionInteraction
{
    private:
        /// La liste des intéractions
        std::list<Interaction> listInteraction;
        /// Le gestionnaire de taches
        GestionTodo* listTodo;

    public:
        /// Constructeur par défaut du gestionnaire d'intéraction
        GestionInteraction();
        /// Destructeur du gestionnaire d'intéraction
        ~GestionInteraction();

        std::list<Interaction> getListInteraction() const{ return listInteraction; }
        void SetlistInteraction(std::list<Interaction> val) { listInteraction = val; }

        GestionTodo* getListTodo() const{ return listTodo; }

        /// Ajouter une interaction
        void addInteraction(const Interaction&);
        /// Supprimer une intéraction
        void removeInteraction(const std::string&);

        /// Ajouter une tache
        void addTodo(const std::string&, Todo&);
        /// Supprimer une tache
        void removeTodo(const std::string&, const std::string&);

        friend std::ostream& operator<<(std::ostream&, const GestionInteraction&);
};

#endif // GESTIONINTERACTION_H
