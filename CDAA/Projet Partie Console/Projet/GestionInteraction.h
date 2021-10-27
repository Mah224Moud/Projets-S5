/**
    *
*/

#ifndef GESTIONINTERACTION_H
#define GESTIONINTERACTION_H

#include <list>
#include <iostream>
#include <ostream>

#include "Interaction.h"
#include "GestionTodo.h"

/**
    *
*/
class GestionInteraction
{
    private:
        std::list<Interaction> listInteraction;
        GestionTodo* listTodo;

    public:
        GestionInteraction();
        ~GestionInteraction();

        std::list<Interaction> getListInteraction() const{ return listInteraction; }
        void SetlistInteraction(std::list<Interaction> val) { listInteraction = val; }

        GestionTodo* getListTodo() const{ return listTodo; }


        void addInteraction(const Interaction&);
        void removeInteraction(const std::string&);

        void addTodo(const std::string&, Todo&);
        void removeTodo(const std::string&, const std::string&);

        friend std::ostream& operator<<(std::ostream&, const GestionInteraction&);
};

#endif // GESTIONINTERACTION_H
