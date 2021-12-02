/**
    *@file Contact.h
    *@brief Fichier d'entête de la classe Contact
    *@author DIALLO Mamoudou
    *@author BAH Saikou Oumar
*/

#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

#include <QDate>
#include <QString>
#include <QDebug>

#include "email.h"
/**
    *@class Contact Contact.h "Contact.h"
    *@brief La classe Contact permet de représenter un contact.
    *@details Un contact est représenté par avec un nom, un prénom,
    une entreprise, un numéro de téléphone, une photo
    et une liste d'intéraction
*/
class Contact
{
    private:
    /// L'identifiant du contact
        QString id;
        QString genID() const;
    /// Le nom du contact
        QString nom;
    /// Le prénom du contact
        QString prenom;
    /// Le nom de l'entreprise
        QString entreprise;
    /// Le numéro du contact
        QString telephone;
    /// La photo du contact
        QString URIphoto;
    /// La date de création du contact
        QDate dateCreation;
    /// La date de dernière modification
        QDate dateLastModif;
    /// Adresse Mail du contact
        Email* mail;

    /// Mise à jour de la date de modification
        void modification();

    public:
    /// Constructeur par défaut de la classe Contact.
    Contact();
    /// Constructeur avec paramètre nom, prénom, entreprise.
    Contact(const QString&, const QString&, const QString&);
    ///
    Contact(const Contact&);
    /// Destructeur de la classe Contact
    ~Contact();

    QString getID() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getEntreprise() const;
    QString getTelephone() const;
    QString getPhoto() const;
    QDate   getDateCreation() const;
    QString getStringDateCreation() const;
    QDate   getDateLastModif() const;
    QString getStringDateLastModif() const;
    QString getEmail() const;

    void setID(const QString&);
    void setNom(const QString&);
    void setPrenom(const QString&);
    void setEntreprise(const QString&);
    void setTelephone(const QString&);
    void setPhoto(const QString&);
    void setDateCreation(const QDate&);
    void setDateCreationFromString(const QString&);
    void setDateLastModif(const QDate&);
    void setDateLastModifFromString(const QString&);
    void setEmail(const QString&);

    friend QDebug operator<<(QDebug, const Contact&);
    QString toString() const;
    bool operator==(const Contact&);
    void operator= (const Contact&);
};

#endif // CONTACT_H_INCLUDED
