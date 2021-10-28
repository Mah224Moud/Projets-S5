/**
    *@file Todo.h
    *@brief Fichier en-tête de la classe Todo
    *@author BAH Saikou Oumar
    *@author DIALLO Mamoudou
*/

#ifndef TODO_H_INCLUDED
#define TODO_H_INCLUDED

#include "Interaction.h"
#include <ctime>
#include <ostream>
/**
    *@class Todo Todo.h "Todo.h"
    *@brief Cette classe permet de créer des taches dans l'application avec une description et une date.
    *@details ...
*/
class Todo
{
    private:
        /// Lien vers l'interaction
        Interaction *lienInteraction;
        /// Le contenu
        std::string contenu;
        /// La date
        struct tm * date;

    public:
        /// Constructeur par défaut
        Todo();
        /// Constructeur avec paramètres
        Todo(Interaction&, const std::string&);

        Interaction getInteraction() const;
        std::string getContenu() const;
        tm getDate() const;

        void setInteraction(Interaction&);
        void setContenu(const std::string&);
        void setDate(const tm&);

        friend std::ostream& operator<<(std::ostream&, const Todo&);

};

#endif // TODO_H_INCLUDED
