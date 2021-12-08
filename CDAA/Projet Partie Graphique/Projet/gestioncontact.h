/**
    *@file gestioncontact.h
    *@brief Fichier d'en-tete de la classe GestionContact
    *@author BAH Saikou Oumar
    *@author DIALLO Mamoudou
*/

#ifndef GESTIONCONTACT_H
#define GESTIONCONTACT_H

#include <list>
#include <QDebug>
#include <QString>

#include "contact.h"
#include "gestioninteraction.h"
#include "gestiontodo.h"

/**
    *@class GestionContact GestionContact.h "GestionContact.h"
    *@brief Cette classe permet de gérer une liste de contact.
    *@details Elle permet notamment d'ajouter, de supprimer des contacts.
    Elle permet aussi l'affichage de toutes les fiches contacts.
*/
class GestionContact
{
private:
    /// La liste des contacts
    std::list<Contact> listContact;
    /// Gestionnaire d'intéractions
    GestionInteraction* gestInteract;
    /// Gestionnaire de tâches
    GestionTodo* gestTodo;

public:
    /// Constructeur du gestionnaire de contact
    GestionContact();
    /// Destructeur du gestionnaire de contact
    ~GestionContact();

    /// Taille de la liste
    inline unsigned getSize(){return listContact.size();}
    /// Accès à la liste des contacts
    std::list<Contact> getListContact() const{ return listContact;}

    /// Accès à la liste des intéractions
    GestionInteraction* getGestInteraction() const{ return gestInteract;}

    /// Accès à la liste des tâches
    GestionTodo* getGestTodo() const{ return gestTodo;}

        /// Ajouter un contact au gestionnaire
        void addContact(const Contact&);
        /// Supprimer un contact
        Contact removeContact(const QString&);
        /// Récuperer un contact en connaissant son id
        Contact getContactByID(const QString&);

        /// Ajouter une intéraction à un contact
        bool addContactInteraction(const QString&, Interaction&);
        /// Supprimer une intéraction à un contact
        bool removeInteraction(const QString&);
        /// Supprimer toutes les intéractions d'un contact
        void removeAllContactInteraction(const QString&);
        /// Récuperer une intéraction d'un contact
        Interaction getInteraction(const QString&);
        /// Récuperer toutes les intéractions d'un contact
        GestionInteraction getAllContactInteraction(const QString&);

        /// Ajouter un todo à une intéraction
        bool addInteractionTodo(const QString&, Todo&);
        /// Récuperer un todo
        Todo getTodo(const QString&);
        /// Supprimer un todo
        bool removeTodo(const QString&);

        friend QDebug operator<<(QDebug, const GestionContact&);
};

#endif // GESTIONCONTACT_H
