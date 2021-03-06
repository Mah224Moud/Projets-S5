/**
    *@file Contact.h
    *@brief Fichier d'entête de la classe Contact
    *@author DIALLO Mamoudou
    *@author BAH Saikou Oumar
*/

#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

#include <string>
#include <list>
#include <ctime>
#include <ostream>
#include "Email.h"
#include "Date.h"
#include "GestionInteraction.h"


/**
    *@class Contact Contact.h "Contact.h"
    *@brief La classe Contact permet de représenter un contact.
    *@details Un contact est représenté par avec un nom, un prénom,
    une entreprise, un numéro de téléphone, une photo
    et une liste d'intéraction
*/
class Contact
{
    private:
    /// Le nom du contact
        std::string nom;
    /// Le prénom du contact
        std::string prenom;
    /// Le nom de l'entreprise
        std::string entreprise;
    /// Le numéro du contact
        std::string telephone;
    /// La photo du contact
        std::string URIphoto;
    /// La date de création du contact
        tm* dateCreation;
    /// La date de dernière modification
        tm* dateLastModif;
    /// Adresse Mail du contact
        Email* mail;
    /// Le gestionnaire des intéractions du contact
        GestionInteraction* listInteractions;

    /// Mise à jour de la date de modification
        void modification();

    public:
    /// Constructeur par défaut de la classe Contact.
    Contact();
    /// Constructeur avec paramètre nom, prénom, entreprise.
    Contact(const std::string&, const std::string&, const std::string&);
    /// Destructeur de la classe Contact
    ~Contact();

    std::string getNom() const;
    std::string getPrenom() const;
    std::string getEntreprise() const;
    std::string getTelephone() const;
    std::string getPhoto() const;
    tm getDateCreation() const;
    tm getDateLastModif() const;
    Email getEmail() const;
    GestionInteraction* getListInteractions() const;


    void setNom(const std::string&);
    void setPrenom(const std::string&);
    void setEntreprise(const std::string&);
    void setTelephone(const std::string&);
    void setPhoto(const std::string&);
    void setDateCreation(const tm&);
    void setDateLastModif(const tm&);
    void setEmail(const std::string&);

    /// Ajouter une interaction
    void addInteraction(const Interaction&);
    /// Supprimer une interaction
    void removeInteraction(const std::string&);

    friend std::ostream& operator<<(std::ostream&, const Contact&);
};

#endif // CONTACT_H_INCLUDED
