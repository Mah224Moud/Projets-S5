/**
    *@file interaction.h
    *@brief Fichier en-tete de la classe Interaction
    *@author BAH Saikou Oumar
    *@author DIALLO Mamoudou
*/

#ifndef INTERACTION_H
#define INTERACTION_H

#include <QString>
#include <QDate>
#include <QDebug>

#include "contact.h"

/**
    @class Interaction Interaction.h "Interaction.h"
    @brief Cette classe décrit des intéractions dans l'application, le contenu et la date de l'interaction;
    @details
*/
class Interaction{
private:
    /// La date de l'intéraction
    QDate date;
    /// L'identifiant de l'intéraction
    QString id;
    /// Détails de l'intéraction
    QString contenu;
    /// Le contact associé
    Contact* contact;

public:
    /// Constructeur par défaut de la classe Interaction
    Interaction();
    /// Constructeur avec paramètre Contact associé
    Interaction(Contact*);
    /// Constructeur avec paramètres Contact associé et contenu de la classe Interaction
    Interaction(Contact *, const QString&);
    /// Constructeur avec paramètres Contact associé, date et contenu de la classe Interaction
    Interaction(Contact *, const QString&, const QDate&);
    /// Constructeur de recopie
    Interaction(const Interaction&);

    QString getID() const;
    QDate getDate() const;
    QString getStringDate() const;
    QString getContenu() const;
    Contact* getContact() const;

    void setDate(const QDate&);
    void setDateFromString(const QString&);
    void setContenu(const QString&);
    void setID(const QString&);
    void setContact(Contact *);

    friend QDebug operator<<(QDebug, const Interaction&);
    QString toString() const;
    bool operator==(const Interaction&);
    void operator= (const Interaction&);
};

#endif // INTERACTION_H
