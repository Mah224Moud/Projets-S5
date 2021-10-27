/**
    *@file Interaction.cpp
    *@brief Fichier CPP de la classe Interaction
    *@author
*/

#include "Interaction.h"

/**
    *@brief Constructeur par défaut.
    *@details Ce constructeur initialise une interaction avec un contenu vide et horodaté avec la date courante.
*/
Interaction::Interaction()
{
    time_t n = time(0);
    date = new tm();
    this->setDate(*localtime(&n));
    this->contenu = "";
}

/**
    *@brief Constructeur avec paramètre
    *@details Ce constructeur initialise une interaction avec un contenu et la date courante.
    *@param c : le contenu de l'interaction
*/
Interaction::Interaction(const std::string& contenu)
{
    time_t n = time(0);
    date = new tm();
    this->setDate(*localtime(&n));
    this -> setContenu(contenu);
}

/**
    *@brief Destructeur de la classe Interaction.
    *@details Libération de l'espace mémoire alloué par date.
*/
Interaction::~Interaction()
{
    //delete date;
}

/// Accesseurs

/**
    *@brief Pour récupérer la date.
    *@details Cette fonction renvoie l'instance pointée par date.
*/
tm Interaction::getDate() const
{
    return *date;
}


/**
    *@brief Pour recupérer le contenu de l'interaction.
    *@details Cette fonction renvoie la chaine contenu de l'interaction.
*/
std::string Interaction::getContenu() const
{
    return this->contenu;
}


/// Mutateurs

/**
    *@brief Pour affecter une date à l'interaction.
    *@param t : structure tm représentant la date à affecter.
    *@details La structure tm t passée en paramètre est copié dans l'instance pointée par date.
*/
void Interaction::setDate(const tm & t)
{
    *date= t;
}

/**
    *@brief Pour affecter un contenu à l'interaction.
    *@param c : string à affecter au contenu.
*/
void Interaction::setContenu(const std:: string & c)
{
    this->contenu= c;
}

/**
    *@brief Surcharge de l'opérateur << pour l'affichage.
    *@param os : de type ostream.
    *@param i: de type Interaction qui represente l'interface à afficher.
    *@details Pour afficher une Interaction, on affiche la date de l'interaction, ou Aujourd'hui s'il s'agit de la date courante, suivie son contenu.
*/
std::ostream& operator<<(std::ostream& os, const Interaction& i)
{
    Date d;
    if(d == i.getDate())    os << "Aujourd'hui ";
    else
    {
        d.setDate(i.getDate());
        os << d.toString()<<" ";
    }
    os << i.getContenu();
    return os;
}


/**

*/
bool Interaction::operator==(const Interaction& autre)
{
    return getContenu() == autre.getContenu();
}

/**

*/
void Interaction::operator=(const Interaction& autre)
{
    setDate(autre.getDate());
    setContenu(autre.getContenu());
}
