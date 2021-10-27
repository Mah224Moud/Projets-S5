/**
    *
*/

#include "GestionTodo.h"

/**
    *
*/
GestionTodo::GestionTodo()
{

}

/**
    *
*/
GestionTodo::~GestionTodo()
{
    listTodo.clear();
}

/**
    *
*/
void GestionTodo::addTodo(const Todo& todo)
{
    listTodo.push_back(todo);
}

/**
    *
*/
void GestionTodo::removeTodo(const std::string& contenu)
{
    auto it = listTodo.begin();
    bool found = false;

    while((it != listTodo.end()) && (found == false))
    {
        if(it->getContenu() == contenu)
        {
            found = true;
            it = listTodo.erase(it);
        }
        else
            it++;
    }
}

/**
    *
*/
void GestionTodo::removeAllInteractionTodo(const Interaction& interact)
{
    auto it = listTodo.begin();
    while(it != listTodo.end())
    {
        if(it->getInteraction() == interact)
        {
            it = listTodo.erase(it);
        }
        else
            it++;
    }
}

/**
    *
*/
GestionTodo GestionTodo::getAllInteractionTodo(const Interaction& interact) const
{
    GestionTodo gest;
    auto it = listTodo.begin();
    while(it != listTodo.end())
    {
        if(it->getInteraction() == interact)
            gest.addTodo(*it);
        it++;
    }

    return gest;
}

/**
    *
*/
std::ostream& operator<<(std::ostream& os, const GestionTodo& gest)
{
    for(auto it : gest.getlistTodo())
    {
        os << it << "\n";
    }

    return os;
}
