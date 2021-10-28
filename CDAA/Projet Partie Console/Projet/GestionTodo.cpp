/**
    *@file GestionTodo.cpp
    *@brief Fichier CPP de la classe GestionTodo.
    *@author BAH Saikou Oumar
    *@author DIALLO Mamoudou
*/

#include "GestionTodo.h"

/**
    *@brief Constructeur par défaut de la classe GestionTodo.
    *@details Rien de particulier dans ce constructeur.
*/
GestionTodo::GestionTodo()
{

}

/**
    *@brief Destructeur de la classe GestionTodo.
    *@details Libération de la mémoire alloué à la liste de tâches.
*/
GestionTodo::~GestionTodo()
{
    listTodo.clear();
}

/**
    *@brief Pour ajouter une tâche à la liste.
    *@details Cette fonction permet d'ajouter une tâche à la liste.
    *@param todo : la tâche (todo) à ajouter.
*/
void GestionTodo::addTodo(const Todo& todo)
{
    listTodo.push_back(todo);
}

/**
    *@brief Pour supprimer une tâche de la liste.
    *@details Cette méthode permet supprimer une tâche en fonction de son contenu.
    *@param contenu :  le contenu de la tâche à supprimer.
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
    *@brief Pour supprimer toutes les tâches liées à une intéraction donné.
    *@details Cette méthode parcourt toute la liste des tâches et supprime toutes celles qui correspondent à l'intéraction.
    *@param interact : l'intéraction dont les tâches sont à supprimer.
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
    *@brief Pour récuperer toutes les tâches d'une intéraction.
    *@details Cette fonction récupère une intéraction et renvoie un gestionnaire de tâches ne contenant que celles qui lui sont liées.
    *@param interact : l'intéraction dont on retournera les tâches;
    *@return un gestionnaire de tâches appartenant toutes à une même intéraction.
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
    *@brief Surcharge de l'opérateur << pour l'affichage.
    *@param os : de type ostream.
    *@param gest: de type GestionTodo qui represente le gestionnaire à afficher.
    *@details Afficher un gestionnaire de tâches revient à afficher toutes les tâches qu'elle contient.
    *@return os
*/
std::ostream& operator<<(std::ostream& os, const GestionTodo& gest)
{
    for(auto it : gest.getlistTodo())
    {
        os << it << "\n";
    }

    return os;
}
