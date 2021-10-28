/**
    *@file GestionInteraction.cpp
    *@brief Fichier CPP de la classe GestionInteraction
    *@author BAH Saikou Oumar
    *@author DIALLO Mamoudou
*/

#include "GestionInteraction.h"

/**
    *@brief Construteur par défaut de la classe GestionInteraction.
    *@details Ce constructeur initialise un gestion de tâches vide.
*/
GestionInteraction::GestionInteraction()
{
    listTodo = new GestionTodo();
}

/**
    *@brief Destructeur de la classe GestionInteraction.
    *@details Libération de la mémoire allouée à la liste d'intéraction et au gestionnaire de tâches.
*/
GestionInteraction::~GestionInteraction()
{
    listInteraction.clear();
    delete listTodo;
}


/**
    *@brief Ajouter une interaction à la liste des intéractions.
    *@details Avant d'inserer l'intéraction dans la liste, on la parcourt pour trouver une intéraction avec une date supérieure.
    L'intéraction est placée dans la liste  juste avant celle-ci, si aucune date supérieure n'a été trouvé, elle est placé en fin de liste.
    De cette façon, on a toujours une liste d'intéraction triée par ordre croissant des dates.
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
    *@brief Supprimer une intéraction de la liste.
    *@details Cette fonction permet de supprimer une intéraction correspondant au contenu donné.
    *@warning La suppression d'une intéraction conduit à la suppression de toutes ses tâches dans le gestionnaire de tâches.
    *@param contenu : le contenu correspondant à la fonction à supprimer.
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
    *@brief Pour ajouter une tâche à une intéraction.
    *@details Cette fonction permet d'ajouter une tâche et de la relier à une intération donnée.
    *@warning Si l'intéraction en question n'existe pas ou n'existe plus, la tâche n'est pas ajoutée et un message d'erreur s'affiche.
    *@param interact_contenu : le contenu de l'intéraction à qui ajouter la tâche;
    *@param td : la tâche à ajouter;
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
    *@brief Pour supprimer une tâche d'une intéraction.
    *@details Cette fonction supprime une tâche en lui indiquant son contenu et le contenu de l'intéraction à laquelle elle appartient.
    *@param interact_contenu : le contenu de l'intéraction;
    *@param todo_contenu : le contenu de la tâche;
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
    *@brief Surcharge de l'opérateur << pour l'affichage.
    *@param os : de type ostream.
    *@param gest: de type GestionInteraction qui represente le gestionnaire à afficher.
    *@details Afficher un gestionnaire d'intéraction revient à afficher toutes les intéractions chacune suivie de l'affichage de toutes ses tâches.
    *@return os
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

