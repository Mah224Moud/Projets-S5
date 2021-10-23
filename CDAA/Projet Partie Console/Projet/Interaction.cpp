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
    return this.date;
}

/**

*/
std::string Interaction::getContenu() const
{

}


/// Mutateurs

void Interaction::setDate()
{

}

void Interaction::setContenu()
{

}

std::ostream& operator<<(std::ostream& os, const Interaction& i)
{

}
