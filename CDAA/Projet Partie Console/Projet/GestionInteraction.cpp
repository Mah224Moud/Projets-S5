/**
    *
*/

#include "GestionInteraction.h"

/**
    *
*/
GestionInteraction::GestionInteraction()
{
    listTodo = new GestionTodo();
}

/**
    *
*/
GestionInteraction::~GestionInteraction()
{
    listInteraction.clear();
    delete listTodo;
}


/**
    *
*/
void GestionInteraction::addInteraction(const Interaction& interact)
{
    Date d;

    auto it = listInteraction.begin();
    bool placeFound = false;
    d.setDate(interact.getDate());

    while((it != listInteraction.end()) && (placeFound == false))
    {
        if(d < it->getDate())
            placeFound = true;
        else
            it++;

    }

    if(placeFound)
        listInteraction.insert(it, interact);
    else
        listInteraction.push_back(interact);
}

/**
    *
*/
void GestionInteraction::removeInteraction(const std::string& contenu)
{
    auto it = listInteraction.begin();
    bool found = false;

    while((it != listInteraction.end()) && (found == false))
    {
        if(it->getContenu() == contenu)
        {
            found = true;
            for(auto td : listTodo->getAllInteractionTodo(*it).getlistTodo())
            {
                removeTodo(it->getContenu(), td.getContenu());
            }
            it = listInteraction.erase(it);
        }
        else
            it++;
    }
}


/**
    *
*/
void GestionInteraction::addTodo(const std::string& interact_contenu, Todo& td)
{
    bool interact_found = false;
    auto it =  listInteraction.begin();

    while((it != listInteraction.end()) && (interact_found == false))
    {
        if(it->getContenu() == interact_contenu)
        {
            interact_found = true;
        }
        else
            it++;
    }

    if(interact_found)
    {
        td.setInteraction(*(it));
        listTodo->addTodo(td);
    }
    else
    {
        std::cout << "Ajout impossible aucune intéraction correspondante à " << interact_contenu << std::endl;
    }

}

/**
    *
*/
void GestionInteraction::removeTodo(const std::string& interact_contenu, const std::string& todo_contenu)
{
    bool found = false;
    auto it =  listInteraction.begin();
    while((it != listInteraction.end()) && found == false)
    {
        if(it->getContenu() == interact_contenu)
        {
            found = true;
            listTodo->removeTodo(todo_contenu);
        }
        else
            it++;
    }
}

/**
    *
*/
std::ostream& operator<<(std::ostream& os, const GestionInteraction& gest)
{
    for(auto it : gest.getListInteraction())
    {
        os << it << "\n";
        for(auto td : gest.getListTodo()->getAllInteractionTodo(it).getlistTodo())
        {
            os << td << "\n";
        }
    }

    return os;
}

