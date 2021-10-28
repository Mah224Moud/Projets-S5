/**
    *@file Contact.cpp
    *@brief Fichier CPP de la classe Contact
    *@author BAH Saikou Oumar
    *@author DIALLO Mamoudou
*/

#include "Contact.h"

/**
    *@brief Constructeur par défaut de la classe Contact
    *@details Ce constructeur initialise un contact avec des attributs et un gestionnaire d'intéractions vides.
    Les dates de création et de modification sont initialisées à la date courante.
*/
Contact::Contact()
{
    nom = "";
    prenom = "";
    entreprise = "";
    mail =  new Email();
    telephone = "";
    URIphoto = "";

    listInteractions = new GestionInteraction();

    time_t n = time(0);
    dateCreation = new tm();
    this->setDateCreation(*localtime(&n));
    dateLastModif = new tm();
    this->setDateLastModif(*localtime(&n));
}

/**
    *@brief Constructeur  de la classe Contact
    *@details Ce constructeur initialise un contact avec les attributs nom, prénom et entreprise.
    Les dates de création et de modification sont initialisées à la date courante, le gestionnaire d'intéraction est vide.
    *@param name : le nom du contact
    *@param lastname : le prénom du contact
    *@param entr : le nom de l'entreprise du contact
*/
Contact::Contact(const std::string& name, const std::string& lastname, const std::string& entr)
{
    nom = name;
    prenom = lastname;
    entreprise = entr;
    mail =  new Email();
    telephone = "";
    URIphoto = "";

    listInteractions = new GestionInteraction();

    time_t n = time(0);
    dateCreation = new tm();
    this->setDateCreation(*localtime(&n));
    dateLastModif = new tm();
    this->setDateLastModif(*localtime(&n));
}

/**
    *@brief Destructeur de la classe Contact
    *@details Rien de particulier, les espaces alloués sont effacés en même tant que le gestionnaire de contact.
    *@warning On obtient une erreur de segmentation (Segmentation fault) si on essaie de libérer l'espace alloué
    par le gestionnaire d'intéraction et une erreur de libération double (double free()) pour celui des dates.
*/
Contact::~Contact()
{
    //delete listInteractions;
    //delete dateCreation;
    //delete dateLastModif;
}

/**
    *@brief Mise à jour de la date de dernière mise à jour.
    *@details Cette méthode permet notamment d'actualiser la date de mise à jour du contact lorsque
    l'un de ses attributs subi une modification. Elle devient la date courante.
*/
void Contact::modification()
{
    Date d;
    setDateLastModif(d.getDate());
}

/**
    *@brief Pour récuperer le nom du contact.
    *@details Cette fonction renvoie le nom du contact.
    *@return Le nom du contact en String
*/
std::string Contact:: getNom() const
{
    return this->nom;
}

/**
    *@brief Pour récuperer le prenom du contact.
    *@details Cette fonction renvoie le prenom du contact.
    *@return Le prenom du contact en String
*/
std::string Contact:: getPrenom() const
{
    return this->prenom;
}

/**
    *@brief Pour récuperer le nom de l'entreprise.
    *@details Cette fonction renvoie le nom de l'entreprise.
    *@return Le nom de l'entreprise en String
*/
std::string Contact:: getEntreprise() const
{
    return this->entreprise;
}

/**
    *@brief Pour récuperer la photo
    *@details Cette fonction ne renvoie pas réellement une photo mais le chemin pour y accéder.
    *@return Le numéro du contact en String
*/
std::string Contact::getTelephone() const
{
    return this->telephone;
}

/**
    *@brief Pour récuperer la photo ou le chemin vers la photo
    *@return Le lien vers kla photo du contact en String
*/
std::string Contact::getPhoto() const
{
    return this->URIphoto;
}

/**
    *@brief Pour récuperer la date de création du contact
    *@return Une tm contenant la date de création du contact
*/
tm Contact::getDateCreation() const
{
    return *dateCreation;
}

/**
    *@brief Pour récuperer la date de dernière modification du contact
    *@return Une tm contenant la date de dernière modification du contact
*/
tm Contact::getDateLastModif() const
{
    return *dateLastModif;
}

/**
    *@brief Pour récupérer l'adresse mail du contact
    *@return Une variable Email contenant l'adresse mail du contact.
*/
Email Contact::getEmail() const
{
    return *mail;
}

/**
    *@brief Pour récuperer la liste des intéractions
    *@details Cette fonction renvoie le pointeur vers le gestionnaire d'interaction.
    *@return Un pointeur sur le gestionnaire d'intéraction.
*/
GestionInteraction* Contact::getListInteractions() const
{
    return listInteractions;
}

/**
    *@brief Pour modifier le nom du contact.
    *@details Cette fonction permet de modifier le nom du contact.
    *@warning Cette opération entraine une mise à jour de la date de modification.
    *@param name : Le nouveau nom du contact.
*/
void Contact::setNom(const std::string& name)
{
    this->nom = name;
    modification();
}

/**
    *@brief Pour modifier le prenom du contact
    *@details Cette fonction permet de modifier le prenom du contact.
    *@warning Cette opération entraine une mise à jour de la date de modification.
    *@param lastname : Le nouveau prénom du contact.
*/
void Contact::setPrenom(const std::string& lastname)
{
    this->prenom = lastname;
    modification();
}

/**
    *@brief Pour modifier le nom de l'entreprise
    *@details Cette fonction permet de modifier le nom de l'entreprise.
    *@warning Cette opération entraine une mise à jour de la date de modification.
    *@param company : Le nouveau nom de l'entreprise.
*/
void Contact::setEntreprise(const std::string& company)
{
    this->entreprise= company;
    modification();
}

/**
    *@brief Pour modifier le numéro du contact
    *@details Cette fonction permet de modifier le numéro du contact.
    *@warning Cette opération entraine une mise à jour de la date de modification.
    *@param phone : Le nouveau numéro du contact.
*/
void Contact::setTelephone(const std::string& phone)
{
    this->telephone = phone;
    modification();
}

/**
    *@brief Pour modifier la photo
    *@warning Cette opération entraine une mise à jour de la date de modification.
    *@param le lien vers la nouvelle photo.
*/
void Contact::setPhoto(const std::string &pic)
{
    this->URIphoto= pic;
    modification();
}

/**
    *@brief Pour modifier la date de création du contact
    *@param date_of_creation :  la date de création du contact.
*/
void Contact:: setDateCreation(const tm& date_of_creation)
{
    *dateCreation = date_of_creation;
}

/**
    *@brief Pour modifier la date de dernière modification
*/
void Contact::setDateLastModif(const tm& last_modif)
{
    *dateLastModif = last_modif;
}

/**
    *@brief Pour modifier l'adresse mail du contact
    *@warning Cette opération entraine une mise à jour de la date de modification.
    *@param email : l'adresse mail sous forme de String.
    *@warning Si l'adresse est incorrecte un message d'erreur s'affiche.
*/
void Contact::setEmail(const std::string &email)
{
    mail->fromString(email);
    modification();
}

/**
    *@brief Ajouter une intéraction au contact
    *@details Cette fonction permet d'ajouter une intéraction dans le gestionnaire.
    *@warning Cette opération entraine une mise à jour de la date de modification.
    *@param add_interact : l'intéraction à ajouter.
*/
void Contact::addInteraction(const Interaction& add_interact)
{
    listInteractions->addInteraction(add_interact);
    modification();
}

/**
    *@brief Supprimer une intéraction au contact
    *@details Cette fonction permet de supprimer une intéraction du gestionnaire en connaissant son contenu.
    *@param contenu_interact : le contenu (String) de l'intéraction à supprimer.
*/
void Contact::removeInteraction(const std::string& contenu_interact)
{
    listInteractions->removeInteraction(contenu_interact);
}

/**
    *@brief Surcharge de l'opérateur << pour l'affichage.
    *@param os : de type ostream.
    *@param c: de type contact qui represente le contact à afficher.
    *@details Pour afficher la fiche d'un contact.
    *@return os
*/
std::ostream& operator<<(std::ostream& os, const Contact& c)
{
    Date d;

    os << "=================> Fiche Contact <=================\n";
    os << "Nom : " << c.getNom() << "\n";
    os << "Prenom : " << c.getPrenom() << "\n";
    os << "Entreprise : " << c.getEntreprise() << "\n";
    os << "Mail : " << c.getEmail().toString()<< "\n";
    os << "Telephone : " << c.getTelephone() << "\n";
    d.setDate(c.getDateCreation());
    os << "Date de création : " << d.toString() << "\n";
    d.setDate(c.getDateLastModif());
    os << "Date de derniere modification : " << d.toString() << "\n";
    os << "Photo : ";
    if(c.getPhoto() == "")  os << "Aucune Photo \n";
    else os << c.getPhoto() << "\n";
    os << "=================> Interactions \n";
    os << *(c.getListInteractions());
    return os;
}
