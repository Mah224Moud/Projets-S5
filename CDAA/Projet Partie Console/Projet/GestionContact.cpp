/**
    *@file GestionContact.cpp
    *@brief Le fichier CPP de la classe GestionContact
*/

#include "GestionContact.h"

/**
    *@brief Constructueur par défaut de la classe GestionContact.
    *@details Rien de particulier.
*/
GestionContact::GestionContact()
{

}

/**
    *@brief Destructeur de la classe GestionContact.
    *@details On libère la mémoire alloué par la liste de contact.
*/
GestionContact::~GestionContact()
{
    listContact.clear();
}


/**
    *@brief Pour ajouter un nouveau contact dans la liste.
    *@param c :  le contact à ajouter
*/
void GestionContact::addContact(const Contact& c)
{
    listContact.push_back(c);
}

/**
    *@todo Demander au prof comment retourner un null lorsque aucun contat trouvé
*/

/*
Contact* GestionContact::getContactByName(const std::string& nom)
{
    auto it = listContact.begin();
    bool found = false;

    while((it != listContact.end()) && (found == false))
    {
        if(it->getNom() == nom)
        {
            found = true;
        }
        else
            it++;
    }

    if(found) return it;
    else return NULL;
}
*/

/**
    *@brief Pour supprimer un contact en connaissant son nom
    *@details Cette fonction permet la suppression d'un contact grâce à son nom.
    On suppose que le nom peut-être qualifié d'identifiant dans un premier temps.
    *@todo Créer la notion d'identifiant, renvoyer le contact supprimé ou un booléen pour signaler la suppression.
    *@param nom : le nom du contact à supprimer.
*/
void GestionContact::removeContact(const std::string& nom)
{
    auto it = listContact.begin();
    bool found = false;

    while((it != listContact.end()) && (found == false))
    {
        if(it->getNom() == nom)
        {
            found = true;
            it = listContact.erase(it);
        }
        else
            it++;
    }
}

/**
    *@brief Surcharge de l'opérateur << pour l'affichage.
    *@param os : de type ostream.
    *@param gest: de type GestionContact qui represente le gestionnaire à afficher.
    *@details Afficher un gestionnaire de contact revient à afficher toutes les fiches de contact à l'intérieur.
    *@return os
*/
std::ostream& operator<<(std::ostream& os, const GestionContact& gest)
{
    for(auto it : gest.getlistContact())
    {
        os << it << "\n\n";
    }
    return os;
}

