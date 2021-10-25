/**
    *@file Interaction.h
    *@brief Fichier en-tete de la classe Interaction
    *@author
*/

#ifndef INTERACTION_H
#define INTERACTION_H

#include <ostream>
#include <string>
#include <ctime>


/**
    @class Interaction
    @brief Cette classe décrit des intéractions dans l'application, le contenu et la date de l'interaction;
    @details
*/
class Interaction{
private:
    tm * date; /// La date de l'intéraction
    std::string contenu; /// Détails de l'intéraction

public:
    Interaction(); /// Constructeur par défaut
    Interaction(const tm&, const std::string &); /// Constructeur avec paramètres
    ~Interaction(); /// Destructeur

    /// Accesseurs
    tm getDate() const;
    std::string getContenu() const;

    /// Mutateurs
    void setDate(const tm&);
    void setContenu(const std::string&);

    friend std::ostream& operator<<(std::ostream&, const Interaction &);
};

#endif // INTERACTION_H
