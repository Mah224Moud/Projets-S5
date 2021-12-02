/**
    *@file GestionInteraction.cpp
    *@brief Fichier CPP de la classe GestionInteraction
    *@author BAH Saikou Oumar
    *@author DIALLO Mamoudou
*/

#include "gestioninteraction.h"

/**
    *@brief Construteur par défaut de la classe GestionInteraction.
*/
GestionInteraction::GestionInteraction()
{

}

/**
    *@brief Destructeur de la classe GestionInteraction.
    *@details Libération de la mémoire allouée à la liste d'intéraction.
*/
GestionInteraction::~GestionInteraction()
{
    listInteraction.clear();
}


/**
    *@brief Ajouter une interaction à la liste des intéractions.
    *@details Avant d'inserer l'intéraction dans la liste, on la parcourt pour trouver une intéraction avec une date supérieure.
    L'intéraction est placée dans la liste  juste avant celle-ci, si aucune date supérieure n'a été trouvé, elle est placé en fin de liste.
    De cette façon, on a toujours une liste d'intéraction triée par ordre croissant des dates.
*/
void GestionInteraction::addInteraction(const Interaction& interact)
{
    auto it = listInteraction.begin();
    bool placeFound = false;

    while((it!= listInteraction.end()) && (!placeFound))
    {
        if(interact.getDate() < it->getDate())
            placeFound = true;
        else
            it++;
    }

    if(placeFound)
        listInteraction.insert(it, interact);
    else
        listInteraction.push_back(interact);

    //qDebug() <<"Contact avant insertion : " << interact.getContact();
    //qDebug() <<"Contact apres insertion : " << listInteraction.end()->getContact();
}

/**
    *@brief Supprimer une intéraction de la liste.
    *@details Cette fonction permet de supprimer une intéraction correspondant a l'identifiant donné.
    *@param contenu : le contenu correspondant à la fonction à supprimer.
*/
bool GestionInteraction::removeInteraction(const QString& idInteract)
{
    auto it = listInteraction.begin();
    bool found = false;

    while((it != listInteraction.end()) && (!found))
    {
        if(it->getID() == idInteract)
        {
            found = true;
            it = listInteraction.erase(it);
        }
        else
            it++;
    }
    return found;
}

/**
    *@brief Pour récuperer toutes les intéractions d'un contact.
    *@details Cette fonction permet de récuperer toutes les intéractions d'un contact.
    *@param idContact : l'identifiant du contact
*/
GestionInteraction GestionInteraction::getAllContactInteraction(const QString& idContact)
{
    GestionInteraction gest;
    auto it = listInteraction.begin();
    while(it != listInteraction.end())
    {
        if(it->getContact()->getID() == idContact)
            gest.addInteraction(*it);
        it++;
    }
    return gest;
}

/**
    *@brief Pour supprimer toutes les intéractions d'un contact.
    *@details Cette fonction permet de supprimer toutes les intéractions d'un contact.
    *@param idContact : l'identifiant du contact
*/
void GestionInteraction::removeAllContactInteraction(const QString& idContact)
{
    auto it = listInteraction.begin();
    while(it != listInteraction.end())
    {
        if(it->getContact()->getID() == idContact)
            it = listInteraction.erase(it);
        else
            it++;
    }
}


/**
    *@brief Surcharge de l'opérateur << pour l'affichage.
    *@param os : de type ostream.
    *@param gest: de type GestionInteraction qui represente le gestionnaire à afficher.
    *@details Afficher un gestionnaire d'intéraction revient à afficher toutes les intéractions du gestionnaire.
    *@return os
*/
QDebug operator<<(QDebug os, const GestionInteraction& gest)
{
    for(auto it : gest.getListInteraction())
    {
        os << it << "\n";
    }

    return os;
}

