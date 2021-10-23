#include "Interaction.h"
#include <ctime>

/**
    *@brief Constructeur par défaut.
    *@details Ce constructeur initialise une interaction avec un contenu vide et horodaté avec la date courante.
*/
Interaction::Interaction()
{
    time_t n = time(0);
    date = new tm();
    this->setDate(*localtime(&n));
}

/**
    *@brief Constructeur avec paramètre
    *@param date : la date de l'interaction
    *@param c : le contenu de l'interaction
*/
Interaction::Interaction(const tm & date, const std::string& contenu)
{
    if(date != nullptr)
        date = new tm();

    this -> setDate(date);
    this -> setContenu(contenu);
}

/**
    *@brief Destructeur de la classe Interaction.
    *@details Libération de l'espace mémoire alloué par date.
*/
Interaction::~Interaction()
{
    delete date;
}

/// Accesseurs

/**
    *@brief Pour récupérer la date.
    *@details Cette fonction renvoie l'instance pointée par date.
*/
tm Interaction::getDate() const
{
    return this->*date;
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
    this->*date= t;
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
    *@details Pour afficher une Interaction, on affiche la date de l'interaction suivie son contenu.
*/
std::ostream& operator<<(std::ostream& os, const Interaction& i)
{
    tm* t= new tm(i.getDate());
    char *d= asctime(t);

    os<<d<<" "<<i.getContenu();
    delete t;

    return os;
}
