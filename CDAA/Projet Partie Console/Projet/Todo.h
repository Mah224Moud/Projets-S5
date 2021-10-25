/**
    *@file Todo.h
    *@brief Fichier en-tête de la classe Todo
    *@author
*/

#ifndef TODO_H_INCLUDED
#define TODO_H_INCLUDED

#include "Interaction.h"
#include <ctime>
#include <ostream>
/**
    *@class Todo
    *@brief Cette classe ...
    *@details ...
*/
class Todo
{
    private:
        Interaction *lienInteraction; /// Lien vers l'interaction
        std::string contenu; /// Le contenu
        struct tm * date; /// La date


    public:
        Todo(); // Constructeur par défaut
        Todo(const Interaction&, const std::string&, const tm&);// Constructeur avec paramètres

        /// Accesseurs
        Interaction getInteraction() const;
        std::string getContenu() const;
        tm getDate() const;

        /// Mutateurs
        void setInteraction(const Interaction&);
        void setContenu(const std::string&);
        void setDate(const tm&);

        friend std::ostream& operator<<(std::ostream&, const Todo&);

};

#endif // TODO_H_INCLUDED
