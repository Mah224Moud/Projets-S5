/**
    *@file Contact.cpp
    *@brief Fichier CPP de la classe Contact
    *@author BAH Saikou Oumar
    *@author DIALLO Mamoudou
*/

#include "contact.h"

/**
    *@brief Constructeur par défaut de la classe Contact
    *@details Ce constructeur initialise un contact avec des attributs et un gestionnaire d'intéractions vides.
    Les dates de création et de modification sont initialisées à la date courante.
*/
Contact::Contact()
{
    id = "";
    nom = "";
    prenom = "";
    entreprise = "";
    telephone = "";
    URIphoto = "";
    dateCreation = QDate::currentDate();
    dateLastModif = QDate::currentDate();
}

/**
    *@brief Constructeur  de la classe Contact
    *@details Ce constructeur initialise un contact avec les attributs nom, prénom et entreprise.
    Les dates de création et de modification sont initialisées à la date courante, le gestionnaire d'intéraction est vide.
    *@param name : le nom du contact
    *@param lastname : le prénom du contact
    *@param entr : le nom de l'entreprise du contact
*/
Contact::Contact(const QString& name, const QString& lastname, const QString& entr)
{
    id = "";
    nom = name;
    prenom = lastname;
    entreprise = entr;
    telephone = "";
    URIphoto = "";
    dateCreation = QDate::currentDate();
    dateLastModif = QDate::currentDate();
}

/**
   *
   *
*/
Contact::Contact(const Contact& autre)
{
    id = autre.getID();
    nom = autre.getNom();
    prenom = autre.getPrenom();
    entreprise = autre.getTelephone();
    telephone = autre.getTelephone();
    URIphoto = autre.getPhoto();
    dateCreation = autre.getDateCreation();
    dateLastModif = autre.getDateLastModif();
    setEmail(autre.getEmail());
}

/**
    *@brief Destructeur de la classe Contact
    *@details Rien de particulier, les espaces alloués sont effacés en même tant que le gestionnaire de contact.
*/
Contact::~Contact()
{

}

/**
    *@brief Mise à jour de la date de dernière mise à jour.
    *@details Cette méthode permet notamment d'actualiser la date de mise à jour du contact lorsque
    l'un de ses attributs subi une modification. Elle devient la date courante.
*/
void Contact::modification()
{
    dateLastModif = QDate::currentDate();
}

/**
    *@brief Pour récuperer l'identifiant du contact.
    *@details Cette fonction renvoie l'identifiant du contact.
    *@return L'identifiant du contact en String
*/
QString Contact::getID() const
{
    return this->id;
}

/**
    *@brief Pour récuperer le nom du contact.
    *@details Cette fonction renvoie le nom du contact.
    *@return Le nom du contact en String
*/
QString Contact::getNom() const
{
    return this->nom;
}

/**
    *@brief Pour récuperer le prenom du contact.
    *@details Cette fonction renvoie le prenom du contact.
    *@return Le prenom du contact en String
*/
QString Contact::getPrenom() const
{
    return this->prenom;
}

/**
    *@brief Pour récuperer le nom de l'entreprise.
    *@details Cette fonction renvoie le nom de l'entreprise.
    *@return Le nom de l'entreprise en String
*/
QString Contact::getEntreprise() const
{
    return this->entreprise;
}

/**
    *@brief Pour récuperer la photo
    *@details Cette fonction ne renvoie pas réellement une photo mais le chemin pour y accéder.
    *@return Le numéro du contact en String
*/
QString Contact::getTelephone() const
{
    return this->telephone;
}

/**
    *@brief Pour récuperer la photo ou le chemin vers la photo
    *@return Le lien vers kla photo du contact en String
*/
QString Contact::getPhoto() const
{
    return this->URIphoto;
}

/**
    *@brief Pour récuperer la date de création du contact
    *@return QDate: la date de création du contact
*/
QDate Contact::getDateCreation() const
{
    return dateCreation;
}

/**
    *@brief Pour récuperer la date de création du contact
    *@return la date de création du contact dans une string au format jj/MM/aaaa
*/
QString Contact::getStringDateCreation() const
{
    return dateCreation.toString("dd/MM/yyyy");
}

/**
    *@brief Pour récuperer la date de dernière modification du contact
    *@return QDate : la date de dernière modification du contact
*/
QDate Contact::getDateLastModif() const
{
    return dateLastModif;
}

/**
    *@brief Pour récuperer la date de dernière modification du contact
    *@return la date de dernière modification du contact dans une string au format jj/MM/aaaa
*/
QString Contact::getStringDateLastModif() const
{
    return dateLastModif.toString("dd/MM/yyyy");
}

/**
    *@brief Pour récupérer l'adresse mail du contact
    *@return Une variable Email contenant l'adresse mail du contact.
*/
QString Contact::getEmail() const
{
    return QString::fromStdString(mail.toString());
}

/**
    *@brief Pour récuperer la liste des intéractions
    *@details Cette fonction renvoie le pointeur vers le gestionnaire d'interaction.
    *@return Un pointeur sur le gestionnaire d'intéraction.
*/

/**
    *@brief Pour modifier l'identifiant du contact.
    *@details Cette fonction permet de modifier l'identifiant du contact.
    *@warning Cette opération entraine une mise à jour de la date de modification.
    *@param name : L'identifiant du contact.
*/
void Contact::setID(const QString& id)
{
    this->id = id;
    //modification();
}


/**
    *@brief Pour modifier le nom du contact.
    *@details Cette fonction permet de modifier le nom du contact.
    *@warning Cette opération entraine une mise à jour de la date de modification.
    *@param name : Le nouveau nom du contact.
*/
void Contact::setNom(const QString& name)
{
    this->nom = name;
    //modification();
}

/**
    *@brief Pour modifier le prenom du contact
    *@details Cette fonction permet de modifier le prenom du contact.
    *@warning Cette opération entraine une mise à jour de la date de modification.
    *@param lastname : Le nouveau prénom du contact.
*/
void Contact::setPrenom(const QString& lastname)
{
    this->prenom = lastname;
    //modification();
}

/**
    *@brief Pour modifier le nom de l'entreprise
    *@details Cette fonction permet de modifier le nom de l'entreprise.
    *@warning Cette opération entraine une mise à jour de la date de modification.
    *@param company : Le nouveau nom de l'entreprise.
*/
void Contact::setEntreprise(const QString& company)
{
    this->entreprise= company;
    //modification();
}

/**
    *@brief Pour modifier le numéro du contact
    *@details Cette fonction permet de modifier le numéro du contact.
    *@warning Cette opération entraine une mise à jour de la date de modification.
    *@param phone : Le nouveau numéro du contact.
*/
void Contact::setTelephone(const QString& phone)
{
    this->telephone = phone;
    //modification();
}

/**
    *@brief Pour modifier la photo
    *@warning Cette opération entraine une mise à jour de la date de modification.
    *@param le lien vers la nouvelle photo.
*/
void Contact::setPhoto(const QString &pic)
{
    this->URIphoto= pic;
    //modification();
}

/**
    *@brief Pour modifier la date de création du contact
    *@param date :  la date de création du contact.
*/
void Contact::setDateCreation(const QDate& date)
{
    dateCreation = date;
}

/**
    *@brief Pour modifier la date de création du contact
    *@param date :  la date de création du contact dans une QString.
*/
void Contact::setDateCreationFromString(const QString& date)
{
    dateCreation = QDate::fromString(date,"dd/MM/yyyy");
}

/**
    *@brief Pour modifier la date de dernière modification
    *@param date: la date de dernière modification
*/
void Contact::setDateLastModifFromString(const QString& date)
{
    dateLastModif = QDate::fromString(date,"dd/MM/yyyy");
}

/**
    *@brief Pour modifier la date de création du contact
    *@param date :  la date de création du contact.
*/
void Contact::setDateLastModif(const QDate& date)
{
    dateLastModif = date;
}

/**
    *@brief Pour modifier l'adresse mail du contact
    *@warning Cette opération entraine une mise à jour de la date de modification.
    *@param email : l'adresse mail sous forme de String.
    *@warning Si l'adresse est incorrecte un message d'erreur s'affiche.
*/
void Contact::setEmail(const QString &email)
{
    mail.fromString(email.toStdString());
    //modification();
}

/**
    *@brief La fiche contact sous forme de string.
*/
QString Contact::toString() const
{
    QString contact = "";
        contact += "=================> Fiche Contact <=================\n";
        contact += "Nom : " + getNom() + "\n";
        contact += "Prenom : " + getPrenom() + "\n";
        contact += "Entreprise : " + getEntreprise() + "\n";
        contact += "Mail : " + getEmail() + "\n";
        contact += "Telephone : " + getTelephone() + "\n";
        contact += "Date de creation : " + getStringDateCreation() + "\n";
        contact += "Date de derniere modification : " + getStringDateLastModif() + "\n";
        if(getPhoto() == "")
            contact += "Aucune Photo\n";
        else
            contact += "Photo : " + getPhoto() + "\n";

    return contact;
}

/**
    *@brief Surcharge de l'opérateur de comparaison d'égalité.
    *@param autre: de type contact.
    *@details Deux contacts sont identiques s'ils ont le même identifiant.
    *@return true si les deux contacts sont identiques false sinon.
*/
bool Contact::operator==(const Contact& autre)
{
    return getID() == autre.getID();
}

/**
    *
    *
*/
void Contact::operator=(const Contact & autre)
{
    id = autre.getID();
    nom = autre.getNom();
    prenom = autre.getPrenom();
    entreprise = autre.getTelephone();
    telephone = autre.getTelephone();
    URIphoto = autre.getPhoto();
    dateCreation = autre.getDateCreation();
    dateLastModif = autre.getDateLastModif();
    setEmail(autre.getEmail());
}


/**
    *@brief Surcharge de l'opérateur << pour l'affichage.
    *@param os : de type ostream.
    *@param c: de type contact qui represente le contact à afficher.
    *@details Pour afficher la fiche d'un contact.
    *@return os
*/

QDebug operator<<(QDebug os, const Contact& c)
{
    os << "=================> Fiche Contact <=================\n";
    os << "id : " << c.getID() << "\n";
    os << "Nom : " << c.getNom() << "\n";
    os << "Prenom : " << c.getPrenom() << "\n";
    os << "Entreprise : " << c.getEntreprise() << "\n";
    os << "Mail : " << c.getEmail()<< "\n";
    os << "Telephone : " << c.getTelephone() << "\n";
    os << "Date de création : " << c.getStringDateCreation() << "\n";
    os << "Date de derniere modification : " << c.getStringDateLastModif() << "\n";
    os << "Photo : ";
    if(c.getPhoto() == "")  os << "Aucune Photo \n";
    else os << c.getPhoto() << "\n";
    return os;
}

