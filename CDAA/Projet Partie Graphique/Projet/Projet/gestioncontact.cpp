/**
    *@file GestionContact.cpp
    *@brief Le fichier CPP de la classe GestionContact
*/

#include "gestioncontact.h"

/**
    *@brief Constructueur par défaut de la classe GestionContact.
    *@details Initialisation des gestionnaires de tâches et d'intéractions.
*/
GestionContact::GestionContact()
{
    gestInteract = new GestionInteraction();
    gestTodo = new GestionTodo();
}

/**
    *@brief Destructeur de la classe GestionContact.
    *@details On libère la mémoire alloué par la liste de contact, les  gestionnaires de tâches et d'intéractions.
*/
GestionContact::~GestionContact()
{
    listContact.clear();
    delete gestInteract;
    delete gestTodo;
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
    *@brief Pour récuperer un contact en connaissant son identifiant.
    *@param idContact: l'identifiant du contact à rechercher.
    *@return Le contact à retrouver.
    *@warning Si le contact est absent de la liste, le contact retourné aura pour identifiant "NULL".
*/
Contact GestionContact::getContactByID(const QString& idContact)
{
    Contact c; c.setID("NULL");
    auto it = listContact.begin();
    bool found = false;
    while((it != listContact.end()) && (!found))
    {
        if(it->getID() == idContact)
        {
            found = true;
            c = *it;
        }
        else
            it++;
    }
    return c;
}

/**
    *@brief Pour supprimer un contact en connaissant son identifiant
    *@details Cette fonction permet la suppression d'un contact grâce à son identifiant.
    *@param idContact : l'identifiant du contact à supprimer.
    *@return Le contact supprimé.
    *@warning La suppression d'un contact entraine la suppression de toutes les intéractions associées de même que toutes les tâches.
    *@warning Si aucun contact ne correspond à cet id, on retourne un contact avec un identifiant "NULL";
*/
Contact GestionContact::removeContact(const QString& idContact)
{
    Contact c; c.setID("NULL");
    auto it = listContact.begin();
    bool found = false;
    while((it != listContact.end()) && (!found))
    {
        if(it->getID() == idContact)
        {
            found = true;
            c = *it;

            removeAllContactInteraction(idContact);

            it = listContact.erase(it);
        }
        else
            it++;
    }
    return c;
}

/**
 * @brief Pour ajouter une intéraction à un contact
 * @param idContact : l'identifiant du contact associé
 * @param interact : l'intéraction à ajouter
 * @return booléen : false si le contact est absent
 */
bool GestionContact::addContactInteraction(const QString& idContact, Interaction& interact)
{
    bool find = false;
    auto contact = listContact.begin();
    while((contact != listContact.end()) && (!find))
    {
        if(contact->getID() == idContact)
        {
            find = true;
            interact.setContact(&(*contact));
            gestInteract->addInteraction(interact);
        }
        contact++;
    }
    return find;
}

/**
 * @brief Pour supprimer une intéraction du gestionnaire d'intéraction.
 * @param idInteract : l'identifiant de l'intéraction à supprimer.
 * @warning La suppression d'une intéraction entraine la suppression de toutes les tâches associées.
 * @return booléen : true si la suppression se passe bien.
 */
bool GestionContact::removeInteraction(const QString& idInteract)
{
    gestTodo->removeAllInteractionTodo(idInteract);
    return gestInteract->removeInteraction(idInteract);
}

/**
 * @brief Pour supprimer toutes les intéractions d'un contact
 * @param idContact : l'identifiant du contact associé
 */
void GestionContact::removeAllContactInteraction(const QString& idContact)
{
    for(auto interact : gestInteract->getListInteraction())
    {
        if(interact.getContact()->getID() == idContact)
            removeInteraction(interact.getID());
    }
}

/**
 * @brief Pour récupérer une intéraction dans le gestionnaire.
 * @param idInteract : l'intéraction à retrouver.
 * @return l'intéraction correspondante.
 */
Interaction GestionContact::getInteraction(const QString& idInteract)
{
    return gestInteract->getInteraction(idInteract);
}

/**
    *@brief Pour récuperer toutes les intéractions d'un contact.
    *@details Cette fonction permet de récuperer toutes les intéractions d'un contact.
    *@param idContact : l'identifiant du contact
*/
GestionInteraction GestionContact::getAllContactInteraction(const QString& idContact)
{
    return gestInteract->getAllContactInteraction(idContact);
}

/**
 * @brief GestionContact::addInteractionTodo
 * @param idInteract
 * @param todo
 * @return
 */
bool GestionContact::addInteractionTodo(const QString& idInteract, Todo& todo)
{
    bool find = false;
    if(gestInteract->getInteractionAdr(idInteract)->getID() != "NULL")
    {
        find = true;
        todo.setInteraction(gestInteract->getInteractionAdr(idInteract));
        gestTodo->addTodo(todo);
    }
    return find;
}

Todo GestionContact::getTodo(const QString& idTodo)
{
    return gestTodo->getTodo(idTodo);
}


/**
    *@brief Surcharge de l'opérateur << pour l'affichage.
    *@param os : de type QDebug.
    *@param gest: de type GestionContact qui represente le gestionnaire à afficher.
    *@details Afficher un gestionnaire de contact revient à afficher toutes les fiches de contact à l'intérieur.
    *@return os
*/
QDebug operator<<(QDebug os, const GestionContact& gest)
{
    for(auto contact : gest.getListContact())
    {
        os << contact << "\n";
        for(auto interact : gest.getGestInteraction()->getAllContactInteraction(contact.getID()).getListInteraction())
        {
            os << interact;
            for(auto todo : gest.getGestTodo()->getAllInteractionTodo(interact.getID()).getlistTodo())
            {
                os << todo;
            }
        }
    }
    return os;
}

