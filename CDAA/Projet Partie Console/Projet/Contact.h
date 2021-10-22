#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED
#include <string>
#include "Email.h"
#include "Date.h"

/**
    *@file Contact.h
    *@brief Fichier d'entête de la classe Contact
    *@author DIALLO Mamoudou
    BAH Saikou Oumar
*/


/**
    *@class Contact
    *@brief La classe Contact permet de représenter un contact.
    *@details Un contact est représenté par avec un nom, un prénom,
    une entreprise, un ou plusieurs numéros de téléphone, une photo
    et une liste d'intéraction
*/
class Contact
{
    private:
        std::string nom;
        std::string prenom;
        std::string entreprise;
        std::string telephone;
        std::string URIphoto;
        Date dateCreation;
        Email mail;



    public:
    Contact();

    std::string getNom();
    void setNom(std::string name);

    std::string getPrenom();
    void setPrenom(std::string lastname);

    std::string getEntreprise();
    void setEntreprise(std::string company);

    std::string getTelephone();
    void setTelephone (std::string phone);

    std::string getPhoto();
    void setPhoto(std::string pic);


};

#endif // CONTACT_H_INCLUDED
