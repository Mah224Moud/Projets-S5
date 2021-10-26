/**
    *@file Contact.cpp
    *@brief Fichier CPP de la classe Contact
    *@author BAH Saikou Oumar
    *@author DIALLO Mamoudou
*/

#include "Contact.h"

/**
    *@brief Constructeur par défaut de la classe Contact
    *@details Ce constructeur initialise un contact avec des attributs vides.
    Les dates de création et de modification sont initialisées à la date courante.
*/
Contact::Contact()
{
    nom = "";
    prenom = "";
    entreprise = "";
    mail = "";
    URIphoto = "";
    Date d;
    *dateCreation = d.getDate();
    *dateLastModif = d.getDate();
}

/**
    *@brief Constructeur  de la classe Contact
    *@details Ce constructeur initialise un contact avec les attributs nom, prénom et entreprise.
    Les dates de création et de modification sont initialisées à la date courante.
    *@param name : le nom du contact
    *@param lastname : le prénom du contact
    *@param entr : le nom de l'entreprise du contact
*/
Contact::Contact(const std::string& name, const std::string& lastname, const std::string& entr)
{
    setNom(name);
    setPrenom(lastname);
    setEntreprise(entr);
    mail = "";
    URIphoto = "";
    Date d;
    *dateCreation = d.getDate();
    *dateLastModif = d.getDate();
}

/**
    *@brief Destructeur de la classe Contact
    *@details Effacement de l'espace alloué par la liste d'interaction, la liste des numéros, les dates de création et de modification.
*/
Contact::~Contact()
{
    listInteractions.clear();
    telephone.clear();
    delete dateCreation;
    delete dateLastModif;
}

/**
    *@brief Pour récuperer le nom du contact.
    *@details Cette fonction renvoie le nom du contact.
*/
std::string Contact:: getNom() const
{
    return this->nom;
}

/**
    *@brief Pour récuperer le prenom du contact.
    *@details Cette fonction renvoie le prenom du contact.
*/
std::string Contact:: getPrenom() const
{
    return this->prenom;
}

/**
    *@brief Pour récuperer le nom de l'entreprise.
    *@details Cette fonction renvoie le nom de l'entreprise.
*/
std::string Contact:: getEntreprise() const
{
    return this->entreprise;
}

