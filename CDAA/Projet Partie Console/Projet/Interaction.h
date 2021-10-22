#include <ostream>
#include <string>

#include "Date.h"

/**
    *@file Interaction.h
    *@brief Fichier en-tete de la classe Interaction
    *@author
*/

/**
    @class Interaction
    @brief Cette Classe décrit des intéractions dans l'application, les détails et la date de l'interaction;
    @details
*/
class Interaction{
private:
    tm * date; /// La date de l'intéraction
    std::string contenu; /// Détails de l'intéraction

public:
    Interaction(); /// Constructeur par défaut
    Interaction(const Date&, const std::string &); /// Constructeur avec paramètres
    ~Interaction(); /// Destructeur

    // Accesseurs
    tm getDate() const;
    std::string getContenu() const;

    // Mutateurs
    void setDate(const Date&);
    void setContenu(const std::string&);

    friend std::ostream& operator<<(std::ostream&, const Interaction &);
};
