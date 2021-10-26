/**
    *@file Interaction.h
    *@brief Fichier en-tete de la classe Interaction
    *@author BAH Saikou Oumar
    *@author DIALLO Mamoudou
*/

#ifndef INTERACTION_H
#define INTERACTION_H

#include <ostream>
#include <string>
#include <ctime>

#include "Date.h"

/**
    @class Interaction Interaction.h "Interaction.h"
    @brief Cette classe décrit des intéractions dans l'application, le contenu et la date de l'interaction;
    @details
*/
class Interaction{
private:
    /// La date de l'intéraction
    tm * date;
    /// Détails de l'intéraction
    std::string contenu;

public:
    /// Constructeur par défaut de la classe Interaction
    Interaction();
    /// Constructeur avec paramètres date et contenu de la classe Interaction
    Interaction(const tm&, const std::string &);
    /// Destructeur de la classe Interaction
    ~Interaction();

    /// Accéder à la date
    tm getDate() const;
    /// Accéder au contenu
    std::string getContenu() const;


    void setDate(const tm&);
    void setContenu(const std::string&);

    friend std::ostream& operator<<(std::ostream&, const Interaction &);
};

#endif // INTERACTION_H
