/**
    *@file Contact.cpp
    *@brief Fichier CPP de la classe Contact
    *@author BAH Saikou Oumar
    *@author DIALLO Mamoudou
*/

#include "Contact.h"

/**
    *@brief Constructeur par défaut de la classe Contact
    *@details Ce constructeur initialise un contact avec des attributs vides.
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

    time_t n = time(0);
    dateCreation = new tm();
    this->setDateCreation(*localtime(&n));
    dateLastModif = new tm();
    this->setDateLastModif(*localtime(&n));
}

/**
    *@brief Constructeur  de la classe Contact
    *@details Ce constructeur initialise un contact avec les attributs nom, prénom et entreprise.
    Les dates de création et de modification sont initialisées à la date courante.
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

    time_t n = time(0);
    dateCreation = new tm();
    this->setDateCreation(*localtime(&n));
    dateLastModif = new tm();
    this->setDateLastModif(*localtime(&n));
}

/**
    *@brief Destructeur de la classe Contact
    *@details Effacement de l'espace alloué par la liste d'interaction, les dates de création et de modification.
*/
Contact::~Contact()
{
    listInteractions.clear();
    delete dateCreation;
    delete dateLastModif;
}

/**
    *@brief Mise à jour de la date de dernière mise à jour.
*/
void Contact::modification()
{
    Date d;
    setDateLastModif(d.getDate());
}

/**
    *@brief Pour récuperer le nom du contact.
    *@details Cette fonction renvoie le nom du contact.
*/
std::string Contact:: getNom() const
{
    return this->nom;
}

/**
    *@brief Pour récuperer le prenom du contact.
    *@details Cette fonction renvoie le prenom du contact.
*/
std::string Contact:: getPrenom() const
{
    return this->prenom;
}

/**
    *@brief Pour récuperer le nom de l'entreprise.
    *@details Cette fonction renvoie le nom de l'entreprise.
*/
std::string Contact:: getEntreprise() const
{
    return this->entreprise;
}

/**
    *@brief Pour récuperer la photo ou le chemin vers la photo
*/
std::string Contact::getTelephone() const
{
    return this->telephone;
}

/**
    *@brief Pour récuperer la photo ou le chemin vers la photo
*/
std::string Contact::getPhoto() const
{
    return this->URIphoto;
}

/**
    *@brief Pour récuperer la date de création du contact
*/
tm Contact::getDateCreation() const
{
    return *dateCreation;
}

/**
    *@brief Pour récuperer la date de dernière modification du contact
*/
tm Contact::getDateLastModif() const
{
    return *dateLastModif;
}

/**
    *@brief Pour récupérer l'adresse mail du contact
*/
Email Contact::getEmail() const
{
    return *mail;
}

/**
    *@brief Pour récuperer la liste des intéractions
*/
std::list<Interaction> Contact::getListInteractions() const
{
    return this->listInteractions;
}

/**
    *@brief Pour modifier le nom du contact
*/
void Contact::setNom(const std::string& name)
{
    this->nom = name;
    modification();
}

/**
    *@brief Pour modifier le prenom du contact
*/
void Contact::setPrenom(const std::string& lastname)
{
    this->prenom = lastname;
    modification();
}

/**
    *@brief Pour modifier le nom de l'entreprise
*/
void Contact::setEntreprise(const std::string& company)
{
    this->entreprise= company;
    modification();
}

/**
    *@brief Pour modifier le numéro du contact
*/
void Contact::setTelephone(const std::string& phone)
{
    this->telephone = phone;
    modification();
}

/**
    *@brief Pour modifier la photo
*/
void Contact::setPhoto(const std::string &pic)
{
    this->URIphoto= pic;
    modification();
}

/**
    *@brief Pour modifier la date de création du contact
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
*/
void Contact::setEmail(const std::string &email)
{
    mail->fromString(email);
    modification();
}

/**
    *@brief Ajouter une intéraction au contact
*/
void Contact::addInteraction(const Interaction& add_interact)
{
    listInteractions.push_back(add_interact);
    modification();
}

/**
    *@brief Supprimer une intéraction au contact
*/
void Contact::removeInteraction(const Interaction& rm_interact)
{

}
/**
    *@brief Surcharge de l'opérateur << pour l'affichage.
    *@param os : de type ostream.
    *@param c: de type contact qui represente le contact à afficher.
    *@details Pour afficher la fiche d'un contact.
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
    for(auto interact : c.getListInteractions())
    {
        os << interact << "\n";
    }
    return os;
}
