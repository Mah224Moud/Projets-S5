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
        std::string identifiant; /// l'dentifiant de l'adresse
        std::string domaine; /// le domaine de l'adresse
        std::string mc; /// le mc de l'adresse

    public:
        Email();
        Email(const std::string&);
        /// Accesseurs
        std::string getIdentifiant() const;
        std::string getDomaine() const;
        std::string getMc() const;
        /// Mutateurs
        void setDomaine(const std::string&);
        void setIdentifiant(const std::string&);
        void setMc(const std::string&);

        void fromString(const std:: string &);
        std:: string toString();
};

#endif // EMAIL_H_INCLUDED
