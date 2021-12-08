/**
    *@file GestionTodo.cpp
    *@brief Fichier CPP de la classe GestionTodo.
    *@author BAH Saikou Oumar
    *@author DIALLO Mamoudou
*/

#include "gestiontodo.h"

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

Todo GestionTodo::getTodo(const QString& idTodo)
{
    Todo td; td.setID("NULL");
    auto it = listTodo.begin();
    bool found = false;
    while((it != listTodo.end()) && (!found))
    {
        if(it->getID() == idTodo)
        {
            found = true;
            td = *it;
        }
            it++;
    }
    return td;
}

/**
    *@brief Pour supprimer une tâche de la liste.
    *@details Cette méthode permet supprimer une tâche en fonction de son contenu.
    *@param contenu :  le contenu de la tâche à supprimer.
    *@return La tâche supprimée
*/
Todo GestionTodo::removeTodo(const QString& id)
{
    Todo td;
    td.setID("NULL");
    auto it = listTodo.begin();
    bool found = false;
    while((it != listTodo.end()) && (!found))
    {
        if(it->getID() == id)
        {
            found = true;
            td = *it;
            it = listTodo.erase(it);
        }
        else
            it++;
    }
    return td;
}

/**
    *@brief Pour supprimer toutes les tâches liées à une intéraction donné.
    *@details Cette méthode parcourt toute la liste des tâches et supprime toutes celles qui correspondent à l'intéraction.
    *@param interact : l'intéraction dont les tâches sont à supprimer.
    *@todo souci à regler: double free apparement
*/
void GestionTodo::removeAllInteractionTodo(const QString& idInteract)
{
    auto it = listTodo.begin();
    while(it != listTodo.end())
    {
        if(it->getInteraction()->getID() == idInteract)
        {
            qDebug()<< it->toString() <<" supprimee";
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
GestionTodo GestionTodo::getAllInteractionTodo(const QString& idInteract)
{
    GestionTodo gest;
    auto it = listTodo.begin();
    while(it != listTodo.end())
    {
        if(it->getInteraction()->getID() == idInteract)
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

QDebug operator<<(QDebug os, const GestionTodo& gest)
{
    for(auto it : gest.getlistTodo())
    {
        os << it.getInteraction()->getID() << " : " << it.toString() << "\n";
    }

    return os;
}

