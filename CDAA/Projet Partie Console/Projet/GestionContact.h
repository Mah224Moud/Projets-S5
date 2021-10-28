/**
    *@file GestionContact.h
    *@brief Fichier d'en-tete de la classe GestionContact
    *@author BAH Saikou Oumar
    *@author DIALLO Mamoudou
*/

#ifndef GESTIONCONTACT_H
#define GESTIONCONTACT_H

#include <list>
#include <ostream>

#include "Contact.h"

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

    public:
        /// Constructeur du gestionnaire de contact
        GestionContact();
        /// Destructeur du gestionnaire de contact
        ~GestionContact();

        /// Accès à la liste des contacts
        std::list<Contact> getlistContact() const{ return listContact;}
        /// Taille de la liste
        inline unsigned getSize(){return listContact.size();}

        /// Ajouter un contact au gestionnaire
        void addContact(const Contact&);
        /// Supprimer un contact
        void removeContact(const std::string&);
        /// Récuperer un contact en connaissant son nom
        Contact* getContactByName(const std::string&);

        friend std::ostream& operator<<(std::ostream&, const GestionContact&);
};

#endif // GESTIONCONTACT_H
