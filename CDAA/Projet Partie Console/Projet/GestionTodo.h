/**
    *
*/

#ifndef GESTIONTODO_H
#define GESTIONTODO_H

#include <list>
#include <ostream>

#include "Todo.h"
#include "Interaction.h"

/**
    *
*/
class GestionTodo
{
    private:
        std::list<Todo> listTodo;

    public:
        GestionTodo();
        ~GestionTodo();

        std::list<Todo> getlistTodo() const{ return listTodo;}
        inline unsigned getSize(){return listTodo.size();}

        void addTodo(const Todo&);
        void removeTodo(const std::string&);
        void removeAllInteractionTodo(const Interaction&);

        GestionTodo getAllInteractionTodo(const Interaction&);

        friend std::ostream& operator<<(std::ostream&, const GestionTodo&);
};

#endif // GESTIONTODO_H
