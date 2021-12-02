/**
    *@file Email.h
    *@brief Fichier d'entête de la classe Email
    *@author DIALLO Mamoudou
    *@author BAH Saikou Oumar
*/

#ifndef EMAIL_H_INCLUDED
#define EMAIL_H_INCLUDED
#include <string>
#include <iostream>

/**
    *@class Email Email.h "Email.h"
    *@brief La classe Email permet de stocker l'adresse mail d'un contact
    *@details Dans la classe email, nous pouvons manipuler séparement toutes les parties de l'adresse.
*/

class Email
{
    private:
        /// L'identifiant de l'adresse
        std::string identifiant;
        /// Le domaine de l'adresse
        std::string domaine;
        /// Le mc de l'adresse
        std::string mc;

    public:
        /// Constructeur par défaut de la classe Email
        Email();
        /// Constructeur avec paramètre de la classe Email
        Email(const std::string&);

        std::string getIdentifiant() const;
        std::string getDomaine() const;
        std::string getMc() const;

        void setDomaine(const std::string&);
        void setIdentifiant(const std::string&);
        void setMc(const std::string&);

        bool fromString(const std:: string &);
        std::string toString();
};

#endif // EMAIL_H_INCLUDED
