#include "Email.h"

using namespace std;

/**
    *@brief Constructeur par défaut de la classe Email.
    *@details Ce constructeur initialise une adresse mail vide.
*/
Email:: Email()
{
    identifiant = "";
    domaine = "";
    mc = "";
}

/**
    *@brief Constructeur avec paramètre de la classe Email.
    *@details Ce constructeur recupère une adresse mail sous forme de String et la décompose pour récuperer les différentes parties en faisant appel à la fonction fromString().
    *@param adr: l'adresse mail sous forme de string
*/
Email::Email(const string& adr)
{
    fromString(adr);
}

/**
    *@brief Pour récuperer la partie identifiant de l'adresse.
    *@details Cette fonction renvoie la partie qui se trouve avant le '@' dans l'adresse mail.
    *@return L'identifiant dans un type String.
*/
string Email::getIdentifiant() const
{
    return this->identifiant;
}

/**
    *@brief Pour definir la partie Identifiant de l'adresse.
    *@param id : l'identifiant de l'adresse
*/
void Email::setIdentifiant(const string& id)
{
    this->identifiant = id;
}

/**
    *@brief Pour récuperer la partie domaine de l'adresse.
    *@details Cette fonction renvoie la partie qui se trouve entre le '@' et le dernier '.' dans l'adresse mail.
    *@return Le domaine de l'adresse mail dans un type String.
*/
string Email::getDomaine() const
{
    return this->domaine;
}

/**
    *@brief Pour definir la partie domaine de l'adresse.
    *@param domaine : le domaine de l'adresse
*/
void Email::setDomaine(const string& domaine)
{
    this->domaine= domaine;
}

/**
    *@brief Pour récuperer la partie mc de l'adresse.
    *@details Cette fonction renvoie la partie qui se trouve après le dernier '.' dans l'adresse mail.
    *@return Le mc dans un type String.
*/
string Email::getMc() const
{
    return this->mc;
}

/**
    *@brief Pour definir la partie mc de l'adresse.
    *@param mc : le mc de l'adresse
*/
void Email::setMc(const string& mc)
{
    this->mc= mc;
}

/**
    *@brief Pour décomposer une adresse mail et récupérer les différentes parties.
    *@details Cette fonction recupère une adresse mail complète (string) et récupére les différentes parties.
    *@warning Si l'adresse mail a une syntaxe incorrecte, aucune partie n'est enregistrée.
    *@param adr : de type String, elle représente l'adresse mail complète;
*/
void Email::fromString(const string& adr)
{
    size_t foundAt, foundPoint, foundLastPoint;

    foundAt = adr.find('@');
    foundLastPoint = adr.find('.', foundAt);

    if(foundAt == string::npos || foundLastPoint == string::npos)
    {
        cout << "Adresse Mail incorrecte" << endl;
        identifiant = "";
        domaine = "";
        mc = "";
    }
    else
    {
        while((foundPoint = adr.find('.', foundLastPoint + 1)) != string::npos)
        {
            foundLastPoint = foundPoint;
        }

        setIdentifiant(adr.substr(0,foundAt));
        setDomaine(adr.substr(foundAt+1, foundLastPoint-(foundAt+1)));
        setMc(adr.substr(foundLastPoint+1));
    }
}

/**
    *@brief Pour reconstituer l'adresse mail en une String
    *@brief Cette fonction retourne, si aucun champ (identifiant, domaine et mc) n'est vide, l'adresse mail recontituée.
    *@return l'adresse mail dans une String.
    *@warning Si l'identifiant, le domaine ou le mc est vide elle renvoie une String vide.
*/
string Email:: toString()
{
    if(getIdentifiant() !=  "" && getDomaine() != "" && getMc() != "")
        return getIdentifiant()+"@"+getDomaine()+"."+getMc();
    else
        return "";
}
